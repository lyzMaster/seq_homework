class Seq {
public:
    int ele[1000];
    int length;
    Seq creat(int length);
    void print_ele();
    int search_ele(int x);
    int delete_ele(int x);
    void selection_sort();
    void quick_sort(int begin, int endd);
    void invert();
    int half_search(int x);
    void insert(int x);
    void delete_range(int begin, int endd);
    void merge_list(Seq seq2);
};

