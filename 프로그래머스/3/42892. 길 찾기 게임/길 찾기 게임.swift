func solution(_ nodeinfo:[[Int]]) -> [[Int]] {
    // y의 내림차순 -> x의 오름차순으로 정렬
    // 하나씩 x를 기준으로 nil이 나올 때까지 왼/오로 재귀적으로 보냄.
    // 전위, 후위 순회하기
    var nodes: [Node] = []
    for i in 0..<nodeinfo.count {
        let pos = nodeinfo[i]
        nodes.append(.init(i+1, pos[0], pos[1]))
    }
    nodes.sort { 
        if $0.y == $1.y {
            return $0.x < $1.x
        }
        return $0.y > $1.y
    }
    
    for i in nodes {
        makeTree(i, nodes.first!)
    }
    
    return [pre(nodes.first!), post(nodes.first!)]
}

class Node {
    var left, right: Node?
    var value, x, y: Int
    
    init(_ value: Int, _ x: Int, _ y: Int) {
        self.value = value
        self.x = x
        self.y = y
    }
}

func makeTree(_ child: Node, _ parent: Node?) {
    guard let parent = parent else { return }
    if parent.x < child.x {
        if parent.right == nil {
            parent.right = child
            return
        } else {
            makeTree(child, parent.right)
        }
    } else if parent.x > child.x {
        if parent.left == nil {
            parent.left = child
            return
        } else {
            makeTree(child, parent.left)
        }
    }
}

func pre(_ node: Node?) -> [Int] {
    guard let node = node else { return [] }
    if node.left == nil && node.right == nil { 
        return  [node.value]
    }
    return [node.value] + pre(node.left) + pre(node.right)
}

func post(_ node: Node?) -> [Int] {
    guard let node = node else { return [] }
    if node.left == nil && node.right == nil { 
        return  [node.value]
    }
    return post(node.left) + post(node.right) + [node.value]
}

