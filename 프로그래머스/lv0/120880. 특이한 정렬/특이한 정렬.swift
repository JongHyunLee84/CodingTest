import Foundation

func solution(_ numlist:[Int], _ n:Int) -> [Int] {
    var array : [Int] = [0]
    var num = 0
    for i in numlist.sorted() {
        for j in 0..<array.count {
            if abs(i - n) <= abs(array[j] - n) {
                array.insert(i, at: j)
                break
            }
            num = i
        }

        if array.contains(num) == false {
            array.append(num)
            }
    }
    array.remove(at: array.firstIndex(of: 0)!)
    return array
}