"use strict";

class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

const head = new Node(10);
head.next = new Node(20);
head.next.next = new Node(30);

function traverse(head) {
  let pointer = head;
  while (pointer !== null) {
    console.log(`[${pointer.data}]->`);
    pointer = pointer.next;
  }
}

traverse(head);
