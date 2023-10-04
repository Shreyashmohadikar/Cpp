class MyHashMap
{
public:
    vector<pair<int, int>> v;
    MyHashMap()
    {
    }

    void put(int key, int value)
    {
        bool flag = 0;

        for (auto &it : v)
        {
            if (it.first == key)
            {
                flag = 1;
                it.second = value;
                break;
            }
        }
        if (flag == 0)
        {
            v.push_back({key, value});
        }
    }

    int get(int key)
    {
        for (auto &it : v)
        {
            if (it.first == key)
            {
                return it.second;
                break;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        for (auto &it : v)
        {
            if (it.first == key)
            {
                it.second = -1;
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */