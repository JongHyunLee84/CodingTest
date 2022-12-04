import Foundation

func solution(_ quiz:[String]) -> [String] {
    var nestedArray = quiz.map { $0.components(separatedBy: " ") }
    var result : [String] = []
    for i in nestedArray {
        var cal = 0 
        switch i[1] {
            case "+":
            cal = Int(i[0])! + Int(i[2])!
            case "-":
            cal = Int(i[0])! - Int(i[2])!
            default :
            break
        }
        if cal == Int(i[4])! {
            result.append("O")
        } else {
            result.append("X")
        }
    }
    return result
}