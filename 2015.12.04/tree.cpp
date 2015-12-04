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
	Tree ():root (NULL)
	{}

	Tree (const Tree<T>& t)
	{
		root = copyTree (t.root);
	}

	Tree<T>& operator = (const Tree<T> &t)
	{
		if (this != &t)
		{
			destroy (root);
			root = copyTree (t.root);		
		}

		return *this;
	}

	~Tree ()
	{
		destroy (root);
	}

	bool empty ()
	{
		return root == NULL;
	}

	void setRoot (const T& newRoot)
	{	

		if (root == NULL)
		{
			root = new TreeNode<T>;
		}
		root->x = newRoot;
	}
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
