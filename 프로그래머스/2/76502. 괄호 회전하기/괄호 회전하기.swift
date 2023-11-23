import Foundation

func solution(_ s:String) -> Int {
    var varS = s
    var ret = 0
    for _ in 0..<s.count {
        var stack: [Character] = []
        for i in varS {
            if i == "]" && (stack.last ?? "]") == "[" {
                stack.removeLast()
            } else if i == "}" && (stack.last ?? "}") == "{" {
                stack.removeLast()
            } else if i == ")" && (stack.last ?? ")") == "(" {
                stack.removeLast()
            } else {
                stack.append(i)
            }
        }
        if stack.isEmpty {
            ret += 1
        }
        let first = varS.removeFirst()
        varS.append(first)
    }
    return ret
}