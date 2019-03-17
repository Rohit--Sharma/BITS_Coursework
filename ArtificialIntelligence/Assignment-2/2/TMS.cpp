#include <stdio.h>
#include <list>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef struct node {
	int id;
	bool state;
	char ruleName[64];
	list<int> *in, *out;
} node;

typedef struct db {
	list<node> *nodes;
} db;

void display(db *database)
{
	cout << "\n\nDatabase state:" << endl;
	for (list<node>::iterator it=database->nodes->begin(); it != database->nodes->end(); ++it) {
		cout << (*it).id << "] " << (*it).state << " " << (*it).ruleName << " (SL (" ;
		bool printComma = false;
		for (list<int>::iterator inIt = (*it).in->begin(); inIt != (*it).in->end(); ++inIt) {
			if (printComma)
				cout << ", ";
			printComma = true;
			cout << *inIt;
		} cout << ") (";
		printComma = false;
		for (list<int>::iterator inIt = (*it).out->begin(); inIt != (*it).out->end(); ++inIt) {
			if (printComma)
				cout << ", ";
			cout << *inIt;
		} cout << "))\n";
	}
	cout << endl;
}

db *input()
{
	db *database = (db *) malloc(sizeof(db));
	database->nodes = new list<node>();
	int noRules, noIn, noOut;
	cout << "Enter no of new rules: ";
	cin >> noRules;
	for (int i = 0; i < noRules; i++) {
		int nodeId = i + 1;
		node *newNode = (node *)malloc(sizeof(node));
		newNode->in = new list<int>();
		newNode->out = new list<int>();
		cout << "Enter the rule name: ";
		char rName[64];
		cin >> rName;
		strcpy(newNode->ruleName, rName);
		newNode->id = nodeId;
		//newNode->ruleName = rName;
		cout << "Is it in or out: ";
		int nodeState;
		cin >> nodeState;
		if (nodeState)
			newNode->state = true;
		else 
			newNode->state = false;
		
		cout << "Enter no of nodes in inlist and outlist: ";
		cin >> noIn >> noOut;
		int inNode;
		cout << "Enter inlist elements: ";
		for (int j = 0; j < noIn; j++) {
			cin >> inNode;
			//cout << "Hello" << endl;
			(newNode->in)->push_back(inNode);
			//cout << "Hello" << endl;
		}
		cout << "Enter outlist elements: ";
		for (int k = 0; k < noOut; k++) {
			cin >> inNode;
			(newNode->out)->push_back(inNode);
		}
		database->nodes->push_back(*newNode);
	}
	
	return database;
}

list<int> input_discoveries()
{
	int noDiscoveries;
	cout << "Enter no of nodes which changed to different state: ";
	cin >> noDiscoveries;
	
	cout << "Enter the node ids which are to be retracted: ";
	list<int> retractedNodes;
	for (int i = 0; i < noDiscoveries; i++) {
		int nodeIdRetracted;
		cin >> nodeIdRetracted;
		retractedNodes.push_back(nodeIdRetracted);
	}
	
	return retractedNodes;
}

db *dependencyDirectedBacktracking(db *oldState, list<int> newDiscoveries)
{
	db *newState = oldState;	//(db *) malloc(sizeof(db));
	
	bool change = true, inCheck, outCheck;
	bool *changedNodes = (bool *) calloc (oldState->nodes->size(), sizeof(bool)); //{false};
	while (change) {
		change = false;
		bool newStateOfNode;
		
		
		for (list<int>::iterator it = newDiscoveries.begin(); it != newDiscoveries.end(); ++it) {
			
			for (list<node>::iterator nodeIt = oldState->nodes->begin(); nodeIt != oldState->nodes->end(); ++nodeIt) {
				if (!changedNodes[nodeIt->id - 1]) {
					// cout << nodeIt->id - 1 << changedNodes[nodeIt->id - 1] << endl;
					if (nodeIt->id == *it) {
						(*nodeIt).state = !((*nodeIt).state);
						newStateOfNode = (*nodeIt).state;
						change = true;
						// cout << changedNodes[nodeIt->id - 1] << endl;
						changedNodes[nodeIt->id - 1] = true;
						// cout << changedNodes[nodeIt->id - 1] << endl;
						break;
					}
				}
			}
			for (list<node>::iterator nodeIt = oldState->nodes->begin(); nodeIt != oldState->nodes->end(); ++nodeIt) {
				if (!changedNodes[nodeIt->id - 1]) {
					if (newStateOfNode == false) {
						list<int>::iterator findIter = find(nodeIt->in->begin(), nodeIt->in->end(), *it);
						if (findIter != nodeIt->in->end()) {
							(*nodeIt).state = !((*nodeIt).state);
							newStateOfNode = (*nodeIt).state;
							change = true;
							changedNodes[nodeIt->id - 1] = true;
							newDiscoveries.push_back(*it);
							break;
						}
					}
					if (newStateOfNode == true) {
						list<int>::iterator findIter = find(nodeIt->out->begin(), nodeIt->out->end(), *it);
						if (findIter != nodeIt->out->end()) {
							(*nodeIt).state = !((*nodeIt).state);
							newStateOfNode = (*nodeIt).state;
							change = true;
							changedNodes[nodeIt->id - 1] = true;
							newDiscoveries.push_back(*it);
							break;
						}
					}
				}
			}
			
		}
		//change = false;
	}
	
	for (list<node>::iterator nodeIt = oldState->nodes->begin(); nodeIt != oldState->nodes->end(); ++nodeIt) {
		inCheck = outCheck = true;
//		cout << "Hello" << endl;
		for(list<int>::iterator it = nodeIt->in->begin(); it != nodeIt->in->end(); it++) {
			for(list<node>::iterator It = oldState->nodes->begin(); It != oldState->nodes->end(); It++) {
//				cout << "Hello1" << endl;
				if(It->state != true && *it == It->id) {
					inCheck = false;
					break;
				}
			}
		}
		
		for(list<int>::iterator it = nodeIt->out->begin(); it != nodeIt->out->end(); it++) {
			for(list<node>::iterator It = oldState->nodes->begin(); It != oldState->nodes->end(); It++) {
				if(It->state != false && *it == It->id) {
					outCheck = false;
					break;
				}
			}
		}
		
		if(outCheck && inCheck && nodeIt->in->size() != 0 && nodeIt->out->size() != 0)
			nodeIt->state = true;
		
	}
	
	return newState;
}

int main() 
{
	db *database = input();
	
	display(database);
	
	list<int> newDiscoveries = input_discoveries();
	
	db *newState = dependencyDirectedBacktracking(database, newDiscoveries);
	
	display(newState);
	cout << endl;
	
	return 0;
}