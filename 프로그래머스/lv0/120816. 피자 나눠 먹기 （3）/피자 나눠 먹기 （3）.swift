import Foundation

func solution(_ slice:Int, _ n:Int) -> Int {
    //slice 2~10까지 변환 가능
    // n명의 사람이 한 조각 이상 
    var result = n / slice
    if n % slice != 0 {
        result += 1
    }
    return result
}