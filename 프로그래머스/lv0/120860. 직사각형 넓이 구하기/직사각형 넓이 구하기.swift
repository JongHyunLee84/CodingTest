import Foundation


func solution(_ dots:[[Int]]) -> Int  {
    var array : [Int] = []
    dots.map {$0.map { array.append($0) } }
    var result : [Int] = []
    if array[0] != array[2] {
        result.append(abs(array[0] - array[2]))
    } else if array[0] != array[4] {
        result.append(abs(array[0] - array[4]))
    }
    if array[1] != array[3] {
        result.append(abs(array[1] - array[3]))
    } else if array[1] != array[5] {
        result.append(abs(array[1] - array[5]))
    }
  return result[0] * result[1]
}