import Foundation

func solution(_ array:[Int]) -> Int {
    var chaList = array.map { Array(String($0)) }.flatMap { $0 }
    return chaList.filter { $0 == "7" }.count 
}

    // var result = array.map { String($0) }.joined()
    // var num = 0
    // for i in result {
    //     if i == "7" {
    //         num += 1
    //     }
    // }
    // return num