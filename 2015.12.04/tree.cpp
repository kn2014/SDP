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
	{
		assert (root != NULL);

		root->children.push_back (copyTree(t.root));
	}
	void print (ostream &out)
private:
	TreeNode<T> *copyTree (const TreeNode<T> *currentNode)
	{
		if (currentNode == NULL)
			return NULL;

		TreeNode<T> *newNode = new TreeNode<T>;

		newNode->x = currentNode->x;

		for (int i = 0; i < currentNode->children.size(); i++)
		{
			newNode->children.push_back (copyTree(currentNode->children[i]));
		}	

		return newNode;
	}
	
	void destroy (const TreeNode<T> *currentNode)
	{
		if (currentNode == NULL)
			return;

		for (int i = 0; i < currentNode->children.size(); i++)
		{
			destroy (currentNode->children[i]);
		}
		
		delete currentNode;

	}
