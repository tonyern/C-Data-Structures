///*
// * Queue.cpp
// *
// *  Created on: Jan 9, 2018
// *      Author: Tony
// */
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//const int maxqueue = 7;
//
//struct queuetype
//{
//    string name[maxqueue];
//    int front;
//    int back;
//};
//
//void createQueue(queuetype &queue);
//bool fullQueue(queuetype queue);
//bool emptyQueue(queuetype queue);
//void enqueue(queuetype &queue, string &newElement);
//void dequeue(queuetype &queue, string &nameOut);
//
//int main()
//{
//    queuetype students;
//    string newElement, nameOut;
//    char quest;
//
//    createQueue(students);
//
//    cout << "Do you want to enter data (Y/N)? ";
//    cin >> quest;
//
//    while ((quest == 'y' || quest == 'Y') && (!(fullQueue(students))))
//    {
//        cout << "Enter name: ";
//        cin >> newElement;
//
//        enqueue(students, newElement);
//
//        if (!(fullQueue(students)))
//        {
//            cout << "Do you want to enter data (Y/N)? ";
//            cin >> quest;
//        }
//    }
//
//    while (!(emptyQueue(students)))
//    {
//        dequeue(students, nameOut);
//        cout << nameOut << endl;
//    }
//
//    return 0;
//}
//
//void createQueue(queuetype &queue)
//{
//    queue.front = maxqueue - 1;
//    queue.back = maxqueue - 1;
//}
//
//bool fullQueue(queuetype queue)
//{
//    if (queue.front == (queue.back + 1) % maxqueue)
//    {
//        return 1;
//    } else {
//        return 0;
//    }
//}
//
//bool emptyQueue(queuetype queue)
//{
//    if (queue.front == queue.back)
//    {
//        return 1;
//    } else {
//        return 0;
//    }
//}
//
//void enqueue(queuetype &queue, string &newElement)
//{
//    queue.back = (queue.back + 1) % maxqueue;
//    queue.name[queue.back] = newElement;
//}
//
//void dequeue(queuetype &queue, string &nameOut)
//{
//    queue.front = (queue.front + 1) % maxqueue;
//    nameOut = queue.name[queue.front];
//}
