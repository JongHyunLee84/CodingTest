import Foundation

func solution(_ strlist:[String]) -> [Int] {
    var result: [Int] = []
    var str = ""
    strlist.map { (i) in
               str = i  
            result.append(Array(str).count)
    }
    return result
}