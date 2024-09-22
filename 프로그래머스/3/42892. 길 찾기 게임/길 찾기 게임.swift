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
    // 노드 정보에 인덱스(ID) 추가 및 y좌표 기준 내림차순, x좌표 기준 오름차순 정렬
    let sortedNodes = nodeinfo.enumerated().map { (index, node) in
        return (id: index + 1, x: node[0], y: node[1])
    }.sorted { 
        if $0.y == $1.y {
            return $0.x < $1.x
        }
        return $0.y > $1.y
    }
    
    // 트리 구성
    let root = buildTree(sortedNodes)
    
    // 전위 순회와 후위 순회 수행
    var preorder: [Int] = []
    var postorder: [Int] = []
    preorderTraversal(root, &preorder)
    postorderTraversal(root, &postorder)
    
    return [preorder, postorder]
}

func buildTree(_ nodes: [(id: Int, x: Int, y: Int)]) -> Node? {
    guard let first = nodes.first else { return nil }
    let root = Node(id: first.id, x: first.x, y: first.y)
    
    for node in nodes.dropFirst() {
        insertNode(root, node)
    }
    
    return root
}

func insertNode(_ parent: Node, _ newNode: (id: Int, x: Int, y: Int)) {
    if newNode.x < parent.x {
        if let left = parent.left {
            insertNode(left, newNode)
        } else {
            parent.left = Node(id: newNode.id, x: newNode.x, y: newNode.y)
        }
    } else {
        if let right = parent.right {
            insertNode(right, newNode)
        } else {
            parent.right = Node(id: newNode.id, x: newNode.x, y: newNode.y)
        }
    }
}

func preorderTraversal(_ node: Node?, _ result: inout [Int]) {
    guard let node = node else { return }
    result.append(node.id)
    preorderTraversal(node.left, &result)
    preorderTraversal(node.right, &result)
}

func postorderTraversal(_ node: Node?, _ result: inout [Int]) {
    guard let node = node else { return }
    postorderTraversal(node.left, &result)
    postorderTraversal(node.right, &result)
    result.append(node.id)
}