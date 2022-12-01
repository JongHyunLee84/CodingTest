import Foundation

func solution(_ score:[[Int]]) -> [Int] {
    var array : [Double] = []
    var result : [Int] = []
    var num = 1
    for i in score {
        array.append((Double(i[0]) + Double(i[1])) / 2)
    }
     for i in array {
         for j in array {
             if i < j {
                 num += 1
             }
         }
         result.append(num)
         num = 1
     }
    return result
}