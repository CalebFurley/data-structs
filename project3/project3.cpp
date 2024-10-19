#include <iostream>
using namespace std;

/*
  Project 3 Data Structures
  Caleb Furley

  Project contains following sections:
    1. CPU Job: Definition & Implementation
    2. Queue: Definition & Implementation
    3. NovelQueue: Definition & Implementation
    4. Testing Via Main()
    5. LLM Usage Documentation
    6. Debug Plan Documentation
*/

/******************* CPUJob Definition & Implementation ********************/
class CPUJob { 
public:     
  int job_id;               // Unique identifier for the job     
  int priority;             // Priority level of the job (1-10)     
  int job_type;             // Job type (1-10)     
  int cpu_time_consumed;    // Total CPU time consumed by the job  
  int memory_consumed;      // Total memory consumed thus far 

  CPUJob();
  CPUJob(int job_id, int priority, int job_type, int cpu_time_consumed, 
    int memory_consumed);
  ~CPUJob();
  void display();
}; 

CPUJob::CPUJob()
: job_id(0), priority(0), job_type(0), cpu_time_consumed(0), memory_consumed(0) {}

CPUJob::CPUJob(int job_id, int priority, int job_type, 
                    int cpu_time_consumed, int memory_consumed) 
: job_id(job_id), priority(priority), job_type(job_type), 
  cpu_time_consumed(cpu_time_consumed), memory_consumed(memory_consumed) {}

CPUJob::~CPUJob() {}

void CPUJob::display() {
  cout << "Job ID: " << job_id << ", Priority: " << priority 
       << ", Job Type: " << job_type << ", CPU Time Consumed: " 
       << cpu_time_consumed << ", Memory Consumed: " << memory_consumed 
       << endl;
}

/******************* Queue Definition & Implementation *********************/

template <class DT> 
class Queue { 
public: 
  DT* jobPointer;           // Pointer to a job (e.g., CPUJob)     
  Queue<DT>* next;          // Pointer to the next node in the queue 

  Queue();
  Queue(DT* jobPointer, Queue<DT>* next);
  ~Queue();
};  

template <class DT>
Queue<DT>::Queue() : jobPointer(nullptr), next(nullptr) {}

template <class DT>
Queue<DT>::Queue(DT* jobPointer, Queue<DT>* next) 
: jobPointer(jobPointer), next(next) {}

template <class DT>
Queue<DT>::~Queue() {
  // Do not delete jobPointer here, as it is managed by NovelQueue
}

/**************** NovelQueue Definition & Implementation *******************/

template <class DT> 
class NovelQueue { 
public:   
  Queue<DT>* front;         // Pointer to the front of the queue
  Queue<DT>* rear;          // Pointer to the rear of the queue   
  Queue<DT>** nodePtrs;     // Array of pointers to Queue nodes     
  int size;                 // Number of elements in the queue 
  int nodePtrLength;        // Store the length of the nodePtr array

  NovelQueue();
  ~NovelQueue();

  void enqueue(DT* newJob);
  DT* dequeue();
  void modify(int job_id, int new_priority, int new_job_type, 
                int new_cpu_time_consumed, int new_memory_consumed);  
  void change(int job_id, int field_index, int new_value);     
  void promote(int job_id, int positions);
  NovelQueue<DT>* reorder(int attribute_index); 
  void display();
  int count();
  void listJobs();

private:
  void customSort(DT** array, int size, bool (*compare)(DT*, DT*));
}; 

template <class DT>
NovelQueue<DT>::NovelQueue() 
: front(nullptr), rear(nullptr), nodePtrs(nullptr), size(0), nodePtrLength(0) {}

template <class DT>
NovelQueue<DT>::~NovelQueue() {
  Queue<DT>* current = front;
  while (current != nullptr) { // Delete all the nodes
    Queue<DT>* tempNext = current->next;
    delete current->jobPointer; // Delete the jobPointer
    delete current;
    current = tempNext;
  }
  delete[] nodePtrs; // Delete pointers to all the nodes
  front = nullptr;
  rear = nullptr;
  nodePtrs = nullptr;
}

template <class DT>
void NovelQueue<DT>::enqueue(DT* newJob) {
  Queue<DT>* newRear = new Queue<DT>(newJob, nullptr);
  if (rear != nullptr) {
    rear->next = newRear;
  }
  rear = newRear;
  if (front == nullptr) {
    front = newRear;
  }

  // Update the nodePtrs array
  if (size == nodePtrLength) {
    int newLength = (nodePtrLength + 1) * 2;
    Queue<DT>** newNodePtrs = new Queue<DT>*[newLength];
    for (int i = 0; i < size; ++i) {
      newNodePtrs[i] = nodePtrs[i];
    }
    for (int i = size; i < newLength; ++i) {
      newNodePtrs[i] = nullptr;
    }
    delete[] nodePtrs;
    nodePtrs = newNodePtrs;
    nodePtrLength = newLength;
  }

  nodePtrs[size] = newRear;
  ++size;
}

template <class DT>
DT* NovelQueue<DT>::dequeue() {
  if (front == nullptr) {
    return nullptr;
  }
  Queue<DT>* oldFront = front;
  DT* job = oldFront->jobPointer;
  front = front->next;
  if (front == nullptr) {
    rear = nullptr;
  }
  delete oldFront;

  // Update the nodePtrs array
  Queue<DT>** newNodePtrs = new Queue<DT>*[size - 1];
  for (int i = 1; i < size; ++i) {
    newNodePtrs[i - 1] = nodePtrs[i];
  }
  delete[] nodePtrs;
  nodePtrs = newNodePtrs;
  --size;

  return job;
}

template <class DT>
void NovelQueue<DT>::modify(int job_id, int new_priority, int new_job_type, 
                    int new_cpu_time_consumed, int new_memory_consumed) {
  for (int i = 0; i < size; ++i) {
    if (nodePtrs[i]->jobPointer->job_id == job_id) {
      nodePtrs[i]->jobPointer->priority = new_priority;
      nodePtrs[i]->jobPointer->job_type = new_job_type;
      nodePtrs[i]->jobPointer->cpu_time_consumed = new_cpu_time_consumed;
      nodePtrs[i]->jobPointer->memory_consumed = new_memory_consumed;
      break;
    }
  }
}

template <class DT>
void NovelQueue<DT>::change(int job_id, int field_index, int new_value) {
  for (int i = 0; i < size; ++i) {
    if (nodePtrs[i]->jobPointer->job_id == job_id) {
      switch (field_index) {
        case 1:
          nodePtrs[i]->jobPointer->priority = new_value;
          break;
        case 2:
          nodePtrs[i]->jobPointer->job_type = new_value;
          break;
        case 3:
          nodePtrs[i]->jobPointer->cpu_time_consumed = new_value;
          break;
        case 4:
          nodePtrs[i]->jobPointer->memory_consumed = new_value;
          break;
        default:
          cout << "Invalid field index!" << endl;
      }
      break;
    }
  }
}

template <class DT>
void NovelQueue<DT>::promote(int job_id, int positions) {
  // TODO: Write this method
}

template <class DT>
NovelQueue<DT>* NovelQueue<DT>::reorder(int attribute_index) {
  // Create a new NovelQueue to hold the reordered jobs
  NovelQueue<DT>* reorderedQueue = new NovelQueue<DT>();

  // Copy the jobs to an array for sorting
  DT** jobsArray = new DT*[size];
  for (int i = 0; i < size; ++i) {
    jobsArray[i] = nodePtrs[i]->jobPointer;
  }

  // Define comparison functions
  auto compareByJobId = [](DT* a, DT* b) { return a->job_id < b->job_id; };
  auto compareByPriority = [](DT* a, DT* b) { return a->priority < b->priority; };
  auto compareByJobType = [](DT* a, DT* b) { return a->job_type < b->job_type; };
  auto compareByCpuTimeConsumed = [](DT* a, DT* b) { return a->cpu_time_consumed < b->cpu_time_consumed; };
  auto compareByMemoryConsumed = [](DT* a, DT* b) { return a->memory_consumed < b->memory_consumed; };

  // Sort the array based on the specified attribute
  switch (attribute_index) {
    case 1: // Sort by job_id
      customSort(jobsArray, size, compareByJobId);
      break;
    case 2: // Sort by priority
      customSort(jobsArray, size, compareByPriority);
      break;
    case 3: // Sort by job_type
      customSort(jobsArray, size, compareByJobType);
      break;
    case 4: // Sort by cpu_time_consumed
      customSort(jobsArray, size, compareByCpuTimeConsumed);
      break;
    case 5: // Sort by memory_consumed
      customSort(jobsArray, size, compareByMemoryConsumed);
      break;
    default:
      cout << "Invalid attribute index!" << endl;
      delete[] jobsArray;
      return nullptr;
  }

  // Enqueue the sorted jobs into the new queue
  for (int i = 0; i < size; ++i) {
    reorderedQueue->enqueue(jobsArray[i]);
  }

  delete[] jobsArray;
  return reorderedQueue;
}

template <class DT>
void NovelQueue<DT>::customSort(DT** array, int size, bool (*compare)(DT*, DT*)) {
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
      if (!compare(array[j], array[j + 1])) {
        DT* temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

template <class DT>
void NovelQueue<DT>::display() {
  Queue<DT>* currentNode = front;
  while (currentNode != nullptr) {
    currentNode->jobPointer->display();  // Use the arrow operator directly
    currentNode = currentNode->next;
  }
}

template <class DT>
int NovelQueue<DT>::count() {
  return size;
}

template <class DT>
void NovelQueue<DT>::listJobs() {
  for (int i = 0; i < size; ++i) {
    nodePtrs[i]->jobPointer->display();
  }
}

/**************************** Testing Via Main *****************************/
int main() {
  int n;  // Number of commands
  cin >> n;  // Read the number of commands

  // Instantiate a NovelQueue for CPUJob pointers
  NovelQueue<CPUJob>* myNovelQueue = new NovelQueue<CPUJob>();
  char command;  // Variable to store the command type
  
  // Variables for job attributes     
  int job_id, priority, job_type, cpu_time_consumed, memory_consumed;        
  
  // Variables for modifying a job     
  int new_priority, new_job_type, new_cpu_time_consumed;     
  int new_memory_consumed;       
  int field_index, new_value;      
  
  // Variable for the number of positions in the 'Promote' command     
  int positions;       
  int attribute_index;  // Variable for the 'Reorder' command

  /************** Read each command Process ***************/
  for (int i = 0; i < n; ++i) {         
    cin >> command;  // Read the command type
    switch (command) {             
      case 'A': {  // Add (Enqueue)       
        cin >> job_id >> priority >> job_type;                      
        cin >> cpu_time_consumed >> memory_consumed;                 
        CPUJob* newJob = new CPUJob(job_id, priority, job_type,      
        cpu_time_consumed, memory_consumed);
        myNovelQueue->enqueue(newJob); 
        cout << "Enqueued Job: " << endl;
        newJob->display();
        cout << "Jobs after enqueue:" << endl;
        myNovelQueue->display();
        break;             
      }             
      case 'R': {  // Remove (Dequeue)                 
        CPUJob* removedJob = myNovelQueue->dequeue();
        if (removedJob) {
          cout << "Dequeued Job: " << endl;
          removedJob->display();
          delete removedJob;  // Clean up memory after use                 
        }
        cout << "Jobs after dequeue:" << endl;
        myNovelQueue->display();
        break;             
      }             
      case 'M': {  // Modify                 
        cin >> job_id >> new_priority >> new_job_type;                 
        cin >> new_cpu_time_consumed >> new_memory_consumed;                 
        myNovelQueue->modify(job_id, new_priority, new_job_type,                               
                      new_cpu_time_consumed, new_memory_consumed);   
        cout << "Modified Job ID " << job_id << ":" << endl;
        for (int i = 0; i < myNovelQueue->size; ++i) {
          if (myNovelQueue->nodePtrs[i]->jobPointer->job_id == job_id) {
            myNovelQueue->nodePtrs[i]->jobPointer->display();
            break;
          }
        }
        cout << "Jobs after modification:" << endl;
        myNovelQueue->display();
        break;             
      }             
      case 'C': {  // Change Job Values                 
        cin >> job_id >> field_index >> new_value;                 
        myNovelQueue->change(job_id, field_index, new_value);    
        cout << "Changed Job ID " << job_id << " field " << field_index << " to " << new_value << ":" << endl;
        for (int i = 0; i < myNovelQueue->size; ++i) {
          if (myNovelQueue->nodePtrs[i]->jobPointer->job_id == job_id) {
            myNovelQueue->nodePtrs[i]->jobPointer->display();
            break;
          }
        }
        cout << "Jobs after changing field:" << endl;
        myNovelQueue->display();
        break;             
      }             
      case 'P': {  // Promote                 
        cin >> job_id >> positions;                 
        myNovelQueue->promote(job_id, positions);                 
        cout << "Promoted Job ID " << job_id << " by " << positions << " Position(s):" << endl;
        for (int i = 0; i < myNovelQueue->size; ++i) {
          if (myNovelQueue->nodePtrs[i]->jobPointer->job_id == job_id) {
            myNovelQueue->nodePtrs[i]->jobPointer->display();
            break;
          }
        }
        cout << "Jobs after promotion:" << endl;
        myNovelQueue->display();
        break;             
      }             
      case 'O': {  // Reorder                 
        cin >> attribute_index;                 
        NovelQueue<CPUJob>* reorderedQueue = myNovelQueue->reorder(attribute_index); 
        cout << "Reordered Queue by attribute " << attribute_index << ":" << endl;                 
        reorderedQueue->display();                 
        delete reorderedQueue; // Clean up memory after use
        break;             
      }             
      case 'D': {  // Display                 
        cout << "Displaying all jobs in the queue:" << endl;
        myNovelQueue->display();
        break;             
      }             
      case 'N': {  // Count                 
        cout << "Number of elements in the queue: " << myNovelQueue->count() << endl; 
        break;             
      }             
      case 'L': {  // List Jobs 
        cout << "List of jobs sorted by job IDs:" << endl;
        myNovelQueue->listJobs();                 
        break;             
      }             
      default:                 
        cout << "Invalid command!" << endl;         
    }     
  }      

  delete myNovelQueue; // Cleanup and end program    
  return 0; 
}

/************************ LLM Usage Documentation ***************************/
// Paste LLM usage txt file here..

/*********************** Debug Plan Documentation **************************/
// Paste debug plan txt file here..