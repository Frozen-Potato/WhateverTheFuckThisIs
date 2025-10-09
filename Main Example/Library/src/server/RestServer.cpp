#include "httplib.h"
#include "Library.h"
#include "EnvLoader.h"
#include "MongoLogger.h"

#include <nlohmann/json.hpp>

int main() {
    httplib::Server svr;
    mongocxx::instance instance{};

    EnvLoader env;
    MongoLogger logger(env.getMongoUrl());
    Library library;

    // GET /medias
    svr.Get("/medias", [&](const httplib::Request&, httplib::Response& res) {
        auto books = library.getAllMedias();  // implement this
        nlohmann::json j;
        for (const auto& b : books) {
            j.push_back({
                {"id", b->getId()},
                {"title", b->getName()},
                {"available", b->getAvailability()}
            });
        }
        res.set_content(j.dump(), "application/json");
    });

    // POST /borrow
    svr.Post("/borrow", [&](const httplib::Request& req, httplib::Response& res) {
        auto body = nlohmann::json::parse(req.body);
        int userId = body["userId"];
        int mediaId = body["mediaId"];
        library.borrowItem(userId, mediaId);
        logger.logEvent("INFO", "User " + std::to_string(userId) + " borrowed media " + std::to_string(mediaId));
        res.set_content("{\"status\":\"borrowed\"}", "application/json");
    });

    // POST /return
    svr.Post("/return", [&](const httplib::Request& req, httplib::Response& res) {
        auto body = nlohmann::json::parse(req.body);
        int userId = body["userId"];
        int mediaId = body["mediaId"];
        library.returnItem(userId, mediaId);
        logger.logEvent("INFO", "Returned media id " + std::to_string(mediaId) + " by user " + std::to_string(userId));
        res.set_content("{\"status\":\"returned\"}", "application/json");
    });

    std::cout << "Server listening on http://localhost:8080" << std::endl;
    svr.listen("0.0.0.0", 8080);
}
