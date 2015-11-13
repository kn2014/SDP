#include <vector>
#include <ostream>

template<typename T>
class BinaryHeap{
      static const unsigned top = 0;
   public:
      BinaryHeap() : heap() {}

      int size() const {return heap.size() - 1;}
      void push(const T& element) {
         heap.push_back(element);
         siftUp(size());
      }
      void pop(){
         std::swap(heap[top], heap[size()]);
         heap.pop_back();
         siftDown(top);
      }
      T peek() const {return heap[top];}
      bool isEmpty() const {return heap.empty();}

      void heapify(const std::vector<T> elements){
         //make a heap out of the vector
         }
      }

      void heapsort(std::vector<T>& elements){
        //sort the elements in the heap
         }
      }
      typename std::vector<T>::iterator begin() {return heap.begin();}
      typename std::vector<T>::iterator end() {return heap.end();}
   private:
      std::vector<T> heap;

      void siftUp(int index);
      void siftDown(int index);
      static int getParent(int index) {return (index - 1) / 2;}
      static int leftChild(int index) {return 2 * index + 1;}
      static int rightChild(int index) {return 2 *(index + 1);}
};

template<typename T>
std::ostream& operator<<(std::ostream& out, BinaryHeap<T> binheap){
   if (binheap.isEmpty()){
      out << "[]";
      return out;
   }
   typename std::vector<T>::const_iterator iter = binheap.begin();
   out << "[";
   for (;iter != binheap.end() - 1; ++iter){
      out << *iter << ", ";
   }
   out << *(binheap.end() - 1) << "]";
}

template<typename T>
void BinaryHeap<T>::siftUp(int index){
   int current = index;
   int parent = getParent(current);
   while (current >= top && heap[current] > heap[parent]){
      std::swap(heap[current], heap[parent]);
      current = parent;
      parent = getParent(current);
   }
}

template<typename T>
void BinaryHeap<T>::siftDown(int index){
   	int left, right, maxIndex;
	// взима позициите на децата
	left = leftChild(index);
	right = rightChild(index);
	if (right >= heap.size())
	{
		if (left >= heap.size())
		{
			return; // ако елемента е извън дървото приключваме
		}
		else
		{
			maxIndex = left; // взимаме единственото дете което е в дървото
		}
	}
	else
	{
		// ако и двете деца са в дървото взимаме по-голямото
		if (heap[left] >= heap[right])
		{
			maxIndex = left;
		}
		else
		{
			maxIndex = right;
		}
	}

	if (heap[index] < heap[maxIndex])
		// ако детето е по-голямо го разменяме с баща му
	{

	    swap(heap[maxIndex], heap[index]);

		siftDown(maxIndex);
	}

}
