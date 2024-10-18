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
:job_id(0),priority(0),job_type(0),cpu_time_consumed(0),memory_consumed(0){}

CPUJob::CPUJob(int job_id, int priority, int job_type, 
                    int cpu_time_consumed, int memory_consumed) {
  this->job_id = job_id;
  this->priority = priority;
  this->job_type = job_type;
  this->cpu_time_consumed = cpu_time_consumed;
  this->memory_consumed = memory_consumed;
}

CPUJob::~CPUJob(){}

void CPUJob::display() {
  cout << "Job ID: " << job_id << "," << "Priority: " << priority 
  << "," << "Job Type: " << job_type << "," << "CPU Time Consumed: " 
  << cpu_time_consumed << "," << "Memory Consumed: " << memory_consumed 
  << endl;
}

/******************* Queue Definition & Implementation *********************/

template <class DT> class Queue { 
public:     
  DT* _JobPointer;           // Pointer to a job (e.g., CPUJob)     
  Queue<DT>* _next;          // Pointer to the next node in the queue 

  Queue();
  Queue(DT* JobPointer, Queue<DT>* next);
  ~Queue();
};  

template <class DT>
Queue<DT>::Queue() : _JobPointer(nullptr), _next(nullptr) {}

template <class DT>
Queue<DT>::Queue(DT* JobPointer, Queue<DT>* next) {
  this->_JobPointer = JobPointer;
  this->_next = next;
}

template <class DT>
Queue<DT>::~Queue() {
  delete _JobPointer;
  //NovelQueue deletes nodes.
}

/**************** NovelQueue Definition & Implementation *******************/

template <class DT> class NovelQueue { 
public:   
  Queue<DT>* _front;         // Pointer to the front of the queue
  Queue<DT>* _rear;          // Pointer to the rear of the queue   
  Queue<DT>** _NodePtrs;     // Array of pointers to Queue nodes     
  int size;                  // Number of elements in the queue) 

  NovelQueue();
  NovelQueue(int size);
  ~NovelQueue();

  void enqueue(CPUJob* newJob);
  CPUJob* dequeue();
  void modify(int job_id, int new_priority, int new_job_type, 
                int new_cpu_time_consumed, int new_memory_consumed);  
  void change(int job_id, int field_index, int new_value);     
  void promote(int job_id, int positions);
  NovelQueue<DT>* reorder(int attribute_index); 
  void display();
  int count();
  void listJobs();
}; 

template <class DT>
NovelQueue<DT>::NovelQueue() 
: _front(nullptr), _rear(nullptr), _NodePtrs(nullmptr) {}

template <class DT>
NovelQueue<DT>::NovelQueue(int size) {
  _NodePtrs = new Queue<DT>[size];
  for (int i=0; i < size; ++i)
    _NodePtrs[i] = nullptr;
  _front = _NodePtrs[0];
  _rear = _NodePtrs[size-1];
}

template <class DT>
NovelQueue<DT>::~NovelQueue() {
  Queue<DT>* current = _front;
  while (current != nullptr) { //delete all the nodes
    Queue<DT>* tempNext = current->_next;
    delete current;
    current = tempNext;
  }
  delete[] _NodePtrs; //delete pointers to all the nodes
  _front = nullptr;
  _rear = nullptr;
  _NodePtrs = nullptr;
}

// Adds a new job to the rear of the queue./////////////////////STARTHERE
template <class DT>
void NovelQueue<DT>::enqueue(CPUJob* newJob) {
  Queue<CPUJob>* oldRear = this->_rear;
  Queue<CPUJob>* newRear = new Queue<CPUJob>(newJob, oldRear);
  this->_rear = newRear;
  oldRear = nullptr;
  newRear = nullptr;
  //need to update the nodePtrs* array //<----------------------FIXTHIS
}

template <class DT>
CPUJob *NovelQueue<DT>::dequeue() {
  //TODO write this method
  return nullptr;
}

template <class DT>
void NovelQueue<DT>::modify(int job_id, int new_priority, int new_job_type, 
                    int new_cpu_time_consumed, int new_memory_consumed) {
  //TODO Write this method..
}

template <class DT>
void NovelQueue<DT>::change(int job_id, int field_index, int new_value) {
  //TODO Write this method..
}

template <class DT>
void NovelQueue<DT>::promote(int job_id, int positions) {
  //TODO Write this method..
}

template <class DT>
NovelQueue<DT> *NovelQueue<DT>::reorder(int attribute_index) {
  //TODO Write this method..
  return nullptr;
}

template <class DT>
void NovelQueue<DT>::display() {
  //TODO Write this method..
}

template <class DT>
int NovelQueue<DT>::count() {
  //TODO Write this method..
  return 0;
}

template <class DT>
void NovelQueue<DT>::listJobs() {
  //TODO Write this method..
}

/**************************** Testing Via Main *****************************/
int main() {
  int n;  // Number of commands
  cin >> n;  // Read the number of commands

  // Instantiate a NovelQueue for CPUJob pointers
  NovelQueue<CPUJob*>* myNovelQueue = new NovelQueue<CPUJob*>(n);
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
        (*myNovelQueue).enqueue(newJob);                 
        break;             
      }             
      case 'R': {  // Remove (Dequeue)                 
        CPUJob* removedJob = (*myNovelQueue).dequeue();
        if (removedJob) {
          cout << "Dequeued Job: ";
          (*removedJob).display();
          delete removedJob;  // Clean up memory after use                 
        }                 
        break;             
      }             
      case 'M': {  // Modify                 
        cin >> job_id >> new_priority >> new_job_type;                 
        cin >> new_cpu_time_consumed >> new_memory_consumed;                 
        (*myNovelQueue).modify(job_id, new_priority, new_job_type,                               
                      new_cpu_time_consumed, new_memory_consumed);   
        break;             
      }             
      case 'C': {  // Change Job Values                 
        cin >> job_id >> field_index >> new_value;                 
        (*myNovelQueue).change(job_id, field_index, new_value);    
        break;             
      }             
      case 'P': {  // Promote                 
        cin >> job_id >> positions;                 
        (*myNovelQueue).promote(job_id, positions);                 
        break;             
      }             
      case 'O': {  // Reorder                 
        cin >> attribute_index;                 
        NovelQueue<CPUJob*>* reorderedQueue =                             
                  (*myNovelQueue).reorder(attribute_index); 
        cout << "Reordered Queue:" << endl;                 
        (*reorderedQueue).display();                 
        break;             
      }             
      case 'D': {  // Display                 
        (*myNovelQueue).display();
        break;             
      }             
      case 'N': {  // Count                 
        cout << "Number of elements in the queue: " <<    
                             (*myNovelQueue).count() << endl; 
        break;             
      }             
      case 'L': {  // List Jobs 
        (*myNovelQueue).listJobs();                 
        break;             
      }             
      default:                 
        cout << "Invalid command!" << endl;         
    }     
  }      

  delete myNovelQueue; //cleanup and end program.    
  return 0; 
}

/************************ LLM Usage Documenation ***************************/
//paste llm usage txt file here..

/*********************** Debug Plan Documentation **************************/
//paste debug plan txt file here..
