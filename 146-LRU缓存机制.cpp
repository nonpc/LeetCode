//146. LRU缓存机制
#if 0
/*

运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例:

LRUCache cache = new LRUCache( 2    // 缓存容量  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4


解题思路 : 
创建链表来保存节点 , 使用哈希表来实现对链表节点的查询 ,O(1)
每次get这个节点 , 先在哈希表中查询 , 如果有则将它在链表的位置放置链首 , 更新在哈希表中的位置
如果没有 , 则返回 -1
put时 , 查询节点 , 如果没有 , 要检查链表是否为满 , 满则删链尾节点 , 在进行插入(插在链首) . 不满直接插入
如果有 , 则放置链首 , 更新哈希表中的位置 

*/

class LRUCache 
{
private:
	//缓存容量上限
	int cap;
	//双向链表 , 保存<键,值>
	list<pair<int, int>> cache;
	//哈希表 , 用来实现O(1)的查找
	unordered_map<int, list<pair<int, int>>::iterator> map;
public:
	LRUCache(int capacity) 
	{
		cap = capacity;
	}

	int get(int key) 
	{
		//先在哈希表中饭查找键
		auto it = map.find(key);
		//如果没找到 , 则返回 -1
		if (it == map.end())
			return -1;
		//找到键 , 则将<键 ,值>保存
		pair<int, int> kv = *map[key];
		//在链表中弹出尾部的<键 ,值>
		cache.erase(map[key]);
		//在链表头部插入新的<键 , 值> (更新操作)
		cache.push_front(kv);
		//更新在哈希表中的 值 所对应的链表节点
		map[key] = cache.begin();
		//返回链表中<键 , 值>的值
		return map[key]->second;
	}

	void put(int key, int value) 
	{
		//先在哈希表中饭查找键
		auto it = map.find(key);
		//没有 , 则要判断链表是否为满
		if (it == map.end())
		{
			//如果链表满
			if (cap == cache.size())
			{
				//要删除最后的<键 , 值> , 给新的<键 , 值>预留地方
				//在链表和哈希表中都要删除<键 ,值>
				auto lastPtr = cache.back();
				map.erase(lastPtr.first);
				cache.pop_back();
			}
			//在链表中插入新的<键 ,值> , 并要在哈希表中更新
			cache.push_front(make_pair(key, value));
			//map[key] = cache.begin();
		}
		else
		{
			//如果链表没满
			//将链表中<键 ,值> 提前
			cache.erase(map[key]);
			cache.push_front(make_pair(key,value));
			//map[key] = cache.begin();
		}
		//更新表中的<键 ,值>的对应关系
		map[key] = cache.begin();
	}
};

int main()
{
	LRUCache a(2);
	a.put(1, 1);
	a.put(2, 2);
	cout<<a.get(1)<<endl;
	a.put(3,3);
	cout << a.get(2) << endl;
	a.put(4, 4);
	cout << a.get(1) << endl<< a.get(2) << endl<<
		a.get(3) << endl<<a.get(4) << endl;

	return 0;

}

#endif
