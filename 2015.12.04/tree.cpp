template <class ElemType>
struct TreeNode
{
	ElemType x;
	vector<TreeNode<ElemType>* > children;
	int uid;
	TreeNode ()
	{
		static int currentId = 0;
		uid = currentId;
		currentId++;
	}
};

template <class T>
class Tree
{

private:
	TreeNode<T> *root;
public:
	Tree ()
	Tree (const Tree<T>& t)
	Tree<T>& operator = (const Tree<T> &t)
	~Tree ()
	bool empty ()
	void setRoot (const T& newRoot)
	void addSubTree (const Tree<T>& t)
	void print (ostream &out)
