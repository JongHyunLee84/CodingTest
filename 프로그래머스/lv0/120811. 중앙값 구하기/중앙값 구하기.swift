import Foundation

func solution(_ array:[Int]) -> Int {
    var result = array.sorted()
    return result.count % 2 == 0 ? result[(result.count / 2) - 1] : result[(result.count / 2)]
}