import Foundation

class Node {
    let id: Int
    let x: Int
    let y: Int
    var left: Node?
    var right: Node?
    
    init(id: Int, x: Int, y: Int) {
        self.id = id
        self.x = x
        self.y = y
    }
}

func solution(_ nodeinfo: [[Int]]) -> [[Int]] {
    let nodes = nodeinfo.enumerated().map { Node(id: $0.offset + 1, x: $0.element[0], y: $0.element[1]) }
    let sortedNodes = nodes.sorted { 
        if $0.y == $1.y {
            return $0.x < $1.x
        }
        return $0.y > $1.y
    }
    
    let root = buildTree(sortedNodes)
    
    return [preorder(root), postorder(root)]
}

func buildTree(_ nodes: [Node]) -> Node? {
    guard let root = nodes.first else { return nil }
    
    for node in nodes.dropFirst() {
        insertNode(root, node)
    }
    
    return root
}

func insertNode(_ parent: Node, _ newNode: Node) {
    if newNode.x < parent.x {
        if let left = parent.left {
            insertNode(left, newNode)
        } else {
            parent.left = newNode
        }
    } else {
        if let right = parent.right {
            insertNode(right, newNode)
        } else {
            parent.right = newNode
        }
    }
}

func preorder(_ node: Node?) -> [Int] {
    guard let node = node else { return [] }
    return [node.id] + preorder(node.left) + preorder(node.right)
}

func postorder(_ node: Node?) -> [Int] {
    guard let node = node else { return [] }
    return postorder(node.left) + postorder(node.right) + [node.id]
}