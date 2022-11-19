import Foundation

func solution(_ rsp:String) -> String {
    var array = Array(rsp)
    var result : [Character] = []
    for i in array {
        switch i {
            case "2":
            result.append("0")
            case "0":
            result.append("5")
            case "5":
            result.append("2")
            default:
            break
        }
    }
    return String(result)
}