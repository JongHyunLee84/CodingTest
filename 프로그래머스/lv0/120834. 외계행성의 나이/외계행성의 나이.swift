import Foundation

func solution(_ age:Int) -> String {
    var array = Array(String(age))
    var result : [String] = []
    for i in array {
        switch i {
            case "0":
            result.append("a")
            case "1":
            result.append("b")
            case "2":
            result.append("c")
            case "3":
            result.append("d")
            case "4":
            result.append("e")
            case "5":
            result.append("f")
            case "6":
            result.append("g")
            case "7":
            result.append("h")
            case "8":
            result.append("i")
            case "9":
            result.append("j")
        default:
            break
        }
    }
    return result.joined()
}