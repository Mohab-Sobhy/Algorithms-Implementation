#pragma once

template<typename Elem>
void Heap<Elem>::Initialize(bool (*_IsBefore)(Elem &, Elem &)) {
    a.Initialize();
    IsBefore = _IsBefore;
}

template<typename Elem>
void Heap<Elem>::Destroy() {
    a.Destroy();
}

template<typename Elem>
int Heap<Elem>::Child(int i) {
    try{
        if(i<0) {
            throw runtime_error("invalid index.");
        }
        return i*2+1;
    }
    catch (const runtime_error& e) {
        cerr<<e.what();
        return -1;
    }
}

template<typename Elem>
int Heap<Elem>::Parent(int i) {
    try{
        if(i<0) {
            throw runtime_error("invalid index.");
        }
        return (i-1)/2;
    }
    catch (const runtime_error& e) {
        cerr<<e.what();
        return -1;
    }
}

template<typename Elem>
void Heap<Elem>::MoveUp(int ind) {
    while(ind > 0) {
        if(IsBefore(a[ind], a[Parent(ind)])) {
            Elem temp = a[Parent(ind)];
            a[Parent(ind)] = a[ind];
            a[ind] = temp;
            ind = Parent(ind);
        }
        else {
            return;
        }
    }
}

template<typename Elem>
void Heap<Elem>::Add(Elem e) {
    a.AddLast(e);
    MoveUp(a.getNumOfElements()-1);
}

template<typename Elem>
void Heap<Elem>::Print() {
    a.print();
}

template<typename Elem>
void Heap<Elem>::MoveDown(int ind) {
    int leftChildInd = Child(ind);
    int rightChildInd = leftChildInd+1;
    int targetIndex = ind;//largest value index in case of max heap || minimum value index in case of min heap
    if(leftChildInd<a.getNumOfElements() && IsBefore(a[leftChildInd],a[ind])) {
        targetIndex = leftChildInd;
    }
    if(rightChildInd<a.getNumOfElements() && IsBefore(a[rightChildInd],a[targetIndex])) {
        targetIndex = rightChildInd;
    }
    if(targetIndex != ind) {
        swap(a[ind],a[targetIndex]);
        MoveDown(targetIndex);
    }
}

template<typename Elem>
Elem Heap<Elem>::GetFirst() {
    return a[0];
}

template<typename Elem>
Elem Heap<Elem>::RetrieveFirst(){
    Elem returnValue = GetFirst();
    swap(a[0],a[a.getNumOfElements()-1]);
    a.RemoveLast();
    MoveDown(0);
    return returnValue;
}


inline bool IsBeforeInt(int& a, int& b)
{
    return a<b;
}