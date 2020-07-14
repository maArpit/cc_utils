struct Segtree{
	int size;
	vector<long long> tree;
	
	Segtree(int n){
		size = 1;
		while(size < n) size *= 2;
		tree.assign(2 * size, 0);
	}

	void build(vector<int> &val, int x = 0, int lx = 0, int rx = -1){
		if(rx == -1) rx = size;
		if(rx - lx == 1) {
			if(lx < (int) val.size()) tree[x] = val[lx];
		}
		else{
			int m = (lx + rx) / 2;
			build(val, 2 * x + 1, lx, m);
			build(val, 2 * x + 2, m, rx);
			tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
		}
	}

	void set(int i, int v, int x = 0, int lx = 0, int rx = -1){
		if(rx == -1) rx = size;
		if(rx - lx == 1) tree[x] = v;
		else {
			int m = (lx + rx) / 2;
			if(i < m) set(i, v, 2 * x + 1, lx, m);
			else set(i, v, 2 * x + 2, m, rx);
			tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
		}
	}
	
	long long get(int l, int r, int x = 0, int lx = 0, int rx = -1){
		if(rx == -1) rx = size;
		if(lx >= r || l >= rx) return 0;
		if(lx >= l && rx <= r) return tree[x];
		int m = (lx + rx) / 2;
		return get(l, r, 2 * x + 1, lx, m) + get(l, r, 2 * x + 2, m, rx);
	}
};
