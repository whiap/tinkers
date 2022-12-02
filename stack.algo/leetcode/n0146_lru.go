package main

import (
	"container/list"
)

// LRUCache .
type LRUCache struct {
	Cap  int
	Keys map[int]*list.Element
	List *list.List
}

// pair .
type pair struct {
	K, V int
}

// Constructor .
func Constructor(capacity int) *LRUCache {
	return &LRUCache{
		Cap:  capacity,
		Keys: make(map[int]*list.Element),
		List: list.New(),
	}
}

// Get .
func (c *LRUCache) Get(key int) int {
	if el, ok := c.Keys[key]; ok {
		c.List.MoveToFront(el)
		return el.Value.(pair).V
	}
	return -1
}

// Put .
func (c *LRUCache) Put(key, val int) {
	if el, ok := c.Keys[key]; ok {
		el.Value = pair{K: key, V: val}
		c.List.MoveToFront(el)
	} else {
		el := c.List.PushFront(pair{K: key, V: val})
		c.Keys[key] = el
	}
	if c.List.Len() > c.Cap {
		el := c.List.Back()
		c.List.Remove(el)
		delete(c.Keys, el.Value.(pair).K)
	}
}
