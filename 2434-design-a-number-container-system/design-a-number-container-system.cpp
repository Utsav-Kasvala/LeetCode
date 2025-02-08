class NumberContainers {
    unordered_map<int, int> mp1;
    unordered_map<int, set<int>> mp2;

public:
    NumberContainers() {}

    void change(int index, int number) {
        if (mp1.find(index) == mp1.end())
            mp1[index] = number;
        else {
            int num = mp1[index];
            mp2[num].erase(index);
            if (mp2[num].empty()) {
                mp2.erase(num);
            }
        }
        mp2[number].insert(index);
        mp1[index] = number;
    }

    int find(int number) {
        if (mp2.find(number) != mp2.end() && !mp2[number].empty())
            return *mp2[number].begin();
        else
            return -1;
    }
};
