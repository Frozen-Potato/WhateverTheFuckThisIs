#include <algorithm>
#include <vector>
#include <iostream>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

bool cIf (int n) {
    return n > 4;
}

bool absBelow1(int a, int b){ 
    return abs(a-b) <=1; 
}

int doubleX (int x) {
    return x*2;
}

int addXY (int x, int y){
    return x + y;
}

void printVector(vector<int> &x){
    for_each(x.begin(), x.end(), [](int &n) { cout << n << " "; });
}

void printHeapTree(const vector<int> &x){
    int len = x.size();
    int level = 0;
    int count  = 1;
    int i = 0;
    while (i < len){
        cout << "\t";
        for (int j = 0; j < count && i < len; j++, i++){
            cout << x[i] << " ";
        }
        cout << "\n";
        level++;
        count = 1 << level;
    }
}

template<typename Iter>
string notFoundcheck(Iter i, Iter end){
    return i != end ? to_string(*i) : "Not Found";
}

int main() {

    vector<int> v = {1,2,3,4,5,6,6,5,4,3,3,4};

    vector<int> v1 = {4,5,2,3};


    cout << "<vector 1>for_each: ";
    printVector(v);
    cout << "\n";

    cout << "<vector 2>for_each: ";
    printVector(v1);
    cout << "\n";

    cout << "---------\n";

    cout << "count: ";
    int countV = count(v.begin(), v.end(), 3);
    cout << countV << "\n";

    cout << "count_if: ";
    int countIf = count_if(v.begin(), v.end(), cIf);
    cout << countIf << "\n";

    cout << "---------\n";

    cout << "find: ";
    auto p = find(v.begin(), v.end(), 2);
    cout << notFoundcheck(p, v.end()) << "\n";

    cout << "find_if: ";
    auto pIf = find_if(v.begin(), v.end(), cIf);
    cout << notFoundcheck(pIf, v.end()) << "\n";

    cout << "find_first_of: ";
    auto pfo = find_first_of(v.begin(), v.end(), v1.begin(), v1.end());
    cout << notFoundcheck(pfo, v.end()) << "\n";

    cout << "find_first_of (with predicate): ";
    auto pfoIf = find_first_of(v.begin(), v.end(), v1.begin(), v1.end(), absBelow1);
    cout << notFoundcheck(pfoIf, v.end()) << "\n";

    cout << "---------\n";

    cout << "equal: ";
    bool eq = equal(v.begin(), v.end(), v1.begin());
    cout << eq << "\n";

    cout << "equal (with predicate): ";
    bool eqIf = equal(v.begin(), v.end(), v1.begin(), absBelow1);
    cout << eqIf << "\n";

    cout << "---------\n";

    cout << "mismatch: ";
    auto [p1, p2] = mismatch(v.begin(), v.end(), v1.begin()); 
    cout << notFoundcheck(p1, v.end()) << " " << notFoundcheck(p2, v1.end()) << "\n";

    cout << "mismatch (with predicate): ";
    auto [p1f, p2f] = mismatch(v.begin(), v.end(), v1.begin(), absBelow1);
    cout << notFoundcheck(p1f, v.end()) << " " << notFoundcheck(p2f, v1.end()) << "\n";

    cout << "---------\n";

    cout << "search: ";
    auto psearch = search(v.begin(), v.end(), v1.begin(), v1.end());
    cout << notFoundcheck(psearch, v.end()) << "\n";

    cout << "search (with predicate): ";
    auto psearchIf = search(v.begin(), v.end(), v1.begin(), v1.end(), absBelow1);
    cout << notFoundcheck(psearchIf, v.end()) << "\n";

    cout << "search_n: ";
    auto psearch_n = search_n(v.begin(), v.end(), 2, 1);
    cout << notFoundcheck(psearch_n, v.end()) << "\n";

    cout << "search_n (with predicate): ";
    auto psearch_nIf = search_n(v.begin(), v.end(), 2, 1, absBelow1);
    cout << notFoundcheck(psearch_nIf, v.end()) << "\n";

    cout << "---------\n";

    cout << "transform (unary): ";
    vector<int> doubled(v.size());
    transform(v.begin(), v.end(), doubled.begin(), doubleX);
    for (int x : doubled) cout << x << " ";
    cout << "\n";

    cout << "transform (binary): ";
    vector<int> sum(v1.size());
    transform(v.begin(), v.begin() + v1.size(), v1.begin(), sum.begin(), addXY);
    for (int x : sum) cout << x << " ";
    cout << "\n";

    cout << "---------\n";

    cout << "copy: ";
    vector<int> c1(v.size());
    copy(v.begin(), v.end(), c1.begin());
    for (int x : c1) cout << x << " ";
    cout << "\n";

    cout << "copy_if (n > 4): ";
    vector<int> c2;
    c2.resize(v.size());
    auto itc2 = copy_if(v.begin(), v.end(), c2.begin(), cIf);
    c2.resize(distance(c2.begin(), itc2));
    for (int x : c2) cout << x << " ";
    cout << "\n";

    cout << "copy_n (first 5): ";
    vector<int> c3(5);
    copy_n(v.begin(), 5, c3.begin());
    for (int x : c3) cout << x << " ";
    cout << "\n";

    cout << "copy_backward: ";
    vector<int> c4(v.size());
    copy_backward(v.begin(), v.end(), c4.end());
    for (int x : c4) cout << x << " ";
    cout << "\n";

    cout << "---------\n";

    cout << "move: ";
    vector<int> vMove = {10,20,30,40,50};
    vector<int> c5(vMove.size());
    move(vMove.begin(), vMove.end(), c5.begin());
    for (int x : c5) cout << x << " ";
    cout << "\n";

    cout << "move_backward: ";
    vector<int> vMove2 = {100,200,300,400};
    vector<int> c6(vMove2.size());
    move_backward(vMove2.begin(), vMove2.end(), c6.end());
    for (int x : c6) cout << x << " ";
    cout << "\n";

    cout << "---------\n";

    cout << "unique: ";
    vector<int> u1 = v;  // prevent mutating the original
    auto newEnd = unique(u1.begin(), u1.end());
    u1.erase(newEnd, u1.end());   // shrink container
    for (int x : u1) cout << x << " ";
    cout << "\n";

    cout << "unique (with predicate absBelow1): ";
    vector<int> u2 = v;
    auto newEnd2 = unique(u2.begin(), u2.end(), absBelow1);
    u2.erase(newEnd2, u2.end());
    for (int x : u2) cout << x << " ";
    cout << "\n";

    cout << "unique_copy: ";
    vector<int> uc1(v.size());
    auto ucEnd1 = unique_copy(v.begin(), v.end(), uc1.begin());
    uc1.resize(distance(uc1.begin(), ucEnd1));
    for (int x : uc1) cout << x << " ";
    cout << "\n";

    cout << "unique_copy (with predicate absBelow1): ";
    vector<int> uc2(v.size());
    auto ucEnd2 = unique_copy(v.begin(), v.end(), uc2.begin(), absBelow1);
    uc2.resize(distance(uc2.begin(), ucEnd2));
    for (int x : uc2) cout << x << " ";
    cout << "\n";

    cout << "---------\n";

    cout << "rotate: ";
    vector<int> r1 = v;  // copy v to keep original safe
    rotate(r1.begin(), r1.begin() + 3, r1.end()); // rotate by 3
    for (int x : r1) cout << x << " ";
    cout << "\n";

    cout << "---------\n";

    cout << "partition (n > 4): ";
    vector<int> partV = v;
    auto itPart = partition(partV.begin(), partV.end(), cIf);
    for (int x : partV) cout << x << " ";
    cout << "\n";

    cout << "stable_partition (n > 4): ";
    vector<int> sp1 = v;
    auto itStablePart = stable_partition(sp1.begin(), sp1.end(), cIf);
    for (int x : sp1) cout << x << " ";
    cout << "\n";

    cout << "is_partitioned (n > 4): ";
    bool partCheck = is_partitioned(v.begin(), v.end(), cIf);
    cout << (partCheck ? "true" : "false") << "\n";

    cout << "---------\n";

    cout << "Permutation: \n";
    vector<int> permutationVector = v;
    next_permutation(permutationVector.begin(), permutationVector.end());
    cout << "Next permutation: ";
    printVector(permutationVector);
    cout << "\n";
    cout << "is_permutation: " << (is_permutation(v.begin(), v.end(), permutationVector.begin()) ? "True" : "False");
    cout << "\n";

    cout << "---------\n";

    cout << "Stable Sort: ";
    vector<int> sortedV = v; //For use in binary search
    vector<int> sortedV1 = v1;
    stable_sort(sortedV.begin(), sortedV.end());
    stable_sort(sortedV1.begin(), sortedV1.end());
    printVector(sortedV);
    cout << "\n";

    cout << "---------\n";

    //Side track std::sort vs std::stable_sort
    const int len = 1000000;
    vector<int> randomV(len);
    mt19937 rng(42);
    uniform_int_distribution<int> dist(1,10000);
    for (int &x : randomV) x = dist(rng);

    vector<int> sortV = randomV;
    vector<int> stableSortV = randomV;

    //std::sort
    auto start1 = high_resolution_clock::now();
    sort(sortV.begin(), sortV.end());
    auto end1 = high_resolution_clock::now();
    auto dur1 = duration_cast<milliseconds>(end1 - start1).count();

    //std::stable_sort
    auto start2 = high_resolution_clock::now();
    sort(stableSortV.begin(), stableSortV.end());
    auto end2 = high_resolution_clock::now();
    auto dur2 = duration_cast<milliseconds>(end2 - start2).count();
    cout << "Side tracking.... \nstd::sort vs std::stable_sort(1e6 item): \n";
    cout << "std::sort time:\t" << dur1 << " ms\n";
    cout << "std::stable_sort time:\t" << dur2 << " ms\n";

    cout << "---------\n";

    cout << "Binary Search: \n";
    auto blb = lower_bound(sortedV.begin(), sortedV.end(),4);
    cout << "lower_bound (n = 4): " << *blb << "\n";
    blb = upper_bound(sortedV.begin(), sortedV.end(), 4);
    cout << "upper_bound (n = 4): " << *blb << "\n";

    cout << "binary_search(4): " << (binary_search(sortedV.begin(), sortedV.end(), 4) ? "true" : "false") << endl;
    cout << "binary_search(4): " << (binary_search(sortedV.begin(), sortedV.end(), 4) ? "true" : "false") << endl;

    cout << "equal_range(4): ";
    auto [eq_first, eq_second] = equal_range(sortedV.begin(), sortedV.end(), 4);
    for (auto it = eq_first; it != eq_second; ++it) cout << *it << " ";
    cout << endl;

    cout << "---------\n";

    cout << "Merge: " ;
    vector<int> mergedV(sortedV.size() + sortedV1.size());
    merge(sortedV.begin(), sortedV.end(), sortedV1.begin(), sortedV1.end(), mergedV.begin());
    printVector(mergedV);
    cout << "\n";

    cout << "---------\n";

    cout << "Set:\n";
    cout << "set_union: ";
    vector<int> uniSet(sortedV.size() + sortedV1.size());
    auto it = set_union(sortedV.begin(), sortedV.end(), sortedV1.begin(), sortedV1.end(), uniSet.begin());
    uniSet.resize(distance(uniSet.begin(), it));
    printVector(uniSet);
    cout << "\n";

    cout << "set_intersection: ";
    vector<int> interSet(sortedV.size() + sortedV1.size());
    auto it1 = set_intersection(sortedV.begin(), sortedV.end(), sortedV1.begin(), sortedV1.end(), interSet.begin());
    interSet.resize(distance(interSet.begin(), it1));
    printVector(interSet);
    cout << "\n";

    cout << "set_difference: ";
    vector<int> diffSet(sortedV.size() + sortedV1.size());
    auto it2 = set_difference(sortedV.begin(), sortedV.end(), sortedV1.begin(), sortedV1.end(), diffSet.begin());
    diffSet.resize(distance(diffSet.begin(), it2));
    printVector(diffSet);
    cout << "\n";

    cout << "set_symmetric_difference: ";
    vector<int> synDiffSet(sortedV.size() + sortedV1.size());
    auto it3 = set_symmetric_difference(sortedV.begin(), sortedV.end(), sortedV1.begin(), sortedV1.end(), synDiffSet.begin());
    synDiffSet.resize(distance(synDiffSet.begin(), it3));
    printVector(synDiffSet);
    cout << "\n";

    cout << "---------\n";

    cout << "Heap:\n";

    cout << "make_heap: \n";
    vector<int> heapV = v;
    make_heap(heapV.begin(), heapV.end());
    printHeapTree(heapV);
    cout << "\n";

    cout << "Check heap(is_heap): is \"";
    printVector(heapV); 
    cout << "\" a heap ? " << (is_heap(heapV.begin(), heapV.end()) ? "True" : "False") << "\n";

    cout << "push_heap (0): \n";
    heapV.push_back(0);
    push_heap(heapV.begin(), heapV.end());
    printHeapTree(heapV);
    cout << "\n";

    pop_heap(heapV.begin(), heapV.end());
    cout << "pop_heap (" << heapV.back() << "): \n";
    heapV.pop_back();
    printHeapTree(heapV);
    cout << "\n";

    cout << "sort_heap: \n";
    sort_heap(heapV.begin(), heapV.end());
    printHeapTree(heapV);
    cout << "\n";

    cout << "---------\n";

    return 0;
};