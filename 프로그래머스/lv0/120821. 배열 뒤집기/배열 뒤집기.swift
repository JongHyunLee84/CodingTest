import Foundation

func solution(_ num_list:[Int]) -> [Int] {
    var array: [Int] = num_list
    var result: [Int] = []
    var num = 1
    var i = 0
    // 배열의 뒤 인덱스부터 추출
    for _ in 0...array.count - 1 {

        i = array.count - num
       
        
        result.append(array[i])
         if i == 0 {
            break
        }
        num += 1
    }
    // 다른 배열에 담기
    return result
}