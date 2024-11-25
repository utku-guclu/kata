/**
 * @param {Record<string, Array<string>} graph The adjacency list representing the graph.
 * @param {string} source The source node to start traversal from. Has to be a valid node if graph is non-empty.
 * @return {Array<string>} A BFS-traversed order of nodes.
 */

interface Queue {
  head: Node | null;
  tail: Node | null;
  length: number;
}

interface Node {
  value: string;
  next: Node | null;
}

export default function breadthFirstSearch(
  graph: Record<string, Array<string>>,
  source: string,
) {
  // If there are no nodes in the graph, just return an empty array
  if (Object.keys(graph).length === 0) {
    return [];
  }

  // Initialize a queue to store nodes to be visited. Enqueue the root node.
  const queue = new Queue();
  queue.enqueue(source);

  //Initialize a set to track visited nodes.
  const visited = new Set();

  while (!queue.isEmpty()) {
    const node = queue.dequeue();
    if (!node) {
      break;
    }

    visited.add(node);

    for (let neighbor of graph[node]) {
      if (!visited.has(neighbor)) {
        queue.enqueue(neighbor);
      }
    }
  }
  // The visited nodes is the traversal order.
  return Array.from(visited);
}

/*  Auxiliary classes */

/**
 * A Queue class with O(1) enqueue and dequeue is provided for you.
 * You can use it directly should you wish to.
 *
 * Example usage:
 * const q = new Queue();
 * q.enqueue('a');
 * q.enqueue('b');
 * q.dequeue(); //'a'
 * q.isEmpty(); // False
 */
class Node {
  constructor(value: string) {
    this.value = value;
    this.next = null;
  }
}

class Queue {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }

  isEmpty() {
    return this.length === 0;
  }

  enqueue(item: string) {
    const newNode = new Node(item);
    if (this.isEmpty()) {
      this.head = newNode;
    } else if (this.tail) {
      this.tail.next = newNode;
    }
    this.tail = newNode;
    this.length++;
  }

  dequeue() {
    if (this.isEmpty() || !this.head) {
      return null;
    } else {
      const removedNode = this.head;
      this.head = this.head.next;
      removedNode.next = null;
      this.length--;
      if (this.isEmpty()) {
        this.tail = null;
      }
      return removedNode.value;
    }
  }
}
