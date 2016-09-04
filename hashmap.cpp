#include <iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;


class HashTable
{
public:
	HashTable(int size = 101) : currentsize(0) { thelists.resize(size);}
	bool insert(const string &s);
	bool remove(const string &s);
	bool contain(const string &s) const;
	void makeEmpty();	
private:
	vector<list<string>> thelists;
	int currentsize;
	int myhash(const string &key);
	void rehash();
};


static unsigned int pcount = 4;
static unsigned long parray[pcount] = {53, 97, 105, 253};

int nextprime(int count)
{
	unsigned long *first = parray;
	unsigned long *last = parray + pcount;
	auto pos = lower_bound(first, last, count);
	return pos == last ? *(last - 1) : *pos;
}

int hash(const string &key)
{
	int hashval = 0;
	for(int i = 0; i < key.size(); ++i)
		hashval = hashval * 37 + key[i];
	return hashval;
}

int HashTable::myhash(const string &key)
{
	int hashval = hash(key);
	hashval %= thelists.size();
	if(hashval < 0)
		hashval += thelists.size();
	return hashval;
}

void HashTable::makeEmpty()
{
	for(int i = 0; i < thelists.size(); ++i)
		thelists[i].clear();
}

bool HashTable::contain(const string &key) const
{
	list<string> &whichlist = thelists[myhash(key)];
	auto it = find(whichlist.begin(), whichlist.end(), key);
	if(it == whichlist.end())
		return false;
	return true;
}

void HashTable::rehash()
{
	vector<list<string>> oldlists = thelists;
	thelists.resize(nextprime(currentsize) * 2);
	
}

bool HashTable::remove(const string &s)
{
	auto &whichlist = thelists[myhash(s)];
	auto it = find(whichlist.begin(), whichlist.end(), s);
	if(it == whichlist.end())
		return false;
	whichlist.erase(it);
	return true;		
}

bool HashTable::insert(const string &s)
{
	list<string> &whichlist = thelists[myhash(s)];
	auto it = find(whichlist.begin(), whichlist.end(), s);
	if(it != whichlist.end())
		return false;	
	whichlist.push_back(s);
	if(++currentsize > thelists.size())
		rehash();
	return true;	
}

void HashTable::rehash()
{
	auto oldlists = thelists;
	for(int i = 0; i < thelists.size(); ++i)
		thelists[i].clear();
	for(int i = 0; i < oldlists.size(); ++i)
	{
		auto it = oldlists[i].begin();
		while(it != oldlists[i].end())
		{
			insert(*it++);
		}
	}
}
	
