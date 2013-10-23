#ifndef HISTORIES_H
#define HISTORIES_H

#include <iostream>
#include <vector>
#include "HistorySeq.h"
#include "State.h"
#include "StatePool.h"

using namespace std;

class Histories {
	public:
		friend class Solver;
		
		Histories();
		~Histories();
		
		HistorySeq* addHistorySeq(State *s);
		HistorySeq* addHistorySeq(State *s, long startDepth);
		void readHistories(ifstream &inFile, StatePool *stPool);
		//void setAffected(long seqIdx, long entryIdx);
		//void resetAffected(set<long> &raffected;
		//void updateVal(double defaultVal, set<long> &reachAffectedHistSeq, set<long> &notReachAffectedHistSeq);
		//void eraseNUpdBel(BeliefNode *currNode, set<long> &affectedHistSeq);
		void write (ostream &os);

		inline void add(HistorySeq *histSeq) { allHistSeq.push_back(histSeq); }
		inline long getNHistSeq() { return allHistSeq.size(); }
		inline HistoryEntry* getHistoryEntry(long seqId, long entryId) { return allHistSeq[seqId]->histSeq[entryId]; }
			
	private:
		vector<HistorySeq*> allHistSeq;
};
#endif
