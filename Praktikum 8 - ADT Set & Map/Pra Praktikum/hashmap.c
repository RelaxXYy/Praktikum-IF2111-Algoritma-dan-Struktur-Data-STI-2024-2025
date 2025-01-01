#include "hashmap.h"

// Hash function using division method
static address hash(keytype key) {
    return key % MaxEl;
}

// Linear probing function
static address probe(address addr) {
    return (addr + 1) % MaxEl;
}

void CreateEmpty(HashMap *M) {
    M->Count = Nil;
    for (int i = 0; i < MaxEl; i++) {
        M->Elements[i].Key = Undefined;
        M->Elements[i].Value = Undefined;
    }
}

int IsEmpty(HashMap M) {
    return (M.Count == Nil) ? 1 : 0;
}

int IsFull(HashMap M) {
    return (M.Count == MaxEl) ? 1 : 0;
}

valuetype Value(HashMap M, keytype k) {
    address addr = hash(k);
    address start = addr;
    
    do {
        if (M.Elements[addr].Key == k) {
            return M.Elements[addr].Value;
        }
        addr = probe(addr);
    } while (addr != start && M.Elements[addr].Key != Undefined);
    
    return Undefined;
}

void Insert(HashMap *M, keytype k, valuetype v) {
    if (IsFull(*M)) return;
    
    address addr = hash(k);
    while (M->Elements[addr].Key != Undefined && M->Elements[addr].Key != k) {
        addr = probe(addr);
    }
    
    // If key already exists, update value
    if (M->Elements[addr].Key == k) {
        M->Elements[addr].Value = v;
    } else {
        // Insert new key-value pair
        M->Elements[addr].Key = k;
        M->Elements[addr].Value = v;
        M->Count++;
    }
}

void Delete(HashMap *M, keytype k) {
    address addr = hash(k);
    address start = addr;
    
    do {
        if (M->Elements[addr].Key == k) {
            M->Elements[addr].Key = Undefined;
            M->Elements[addr].Value = Undefined;
            M->Count--;
            return;
        }
        addr = probe(addr);
    } while (addr != start);
}

int IsMember(HashMap M, keytype k) {
    address addr = hash(k);
    address start = addr;
    
    do {
        if (M.Elements[addr].Key == k) {
            return 1;
        }
        addr = probe(addr);
    } while (addr != start && M.Elements[addr].Key != Undefined);
    
    return 0;
}