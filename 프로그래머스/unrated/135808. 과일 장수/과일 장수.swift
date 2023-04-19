import Foundation

func solution(_ k:Int, _ m:Int, _ score:[Int]) -> Int {
    // m개의 사과가 한 상자 -> 점수가 제일 낮은 사과들을 먼저 버리기
    var array = score.sorted()
    var rest = array.count % m
    for _ in 0..<rest {
        array.removeFirst()
    }
    // 한 상자에 낮은 점수 순서대로 몰아넣기
    var boxes: [[Int]] = []
    var box: [Int] = []
    for i in array {
        if box.count < m {
            box.append(i)
        }
        if box.count == m {
            boxes.append(box)
            box = []
        }
    }
    // 각 상자 속에 최저 사과 점수 * 사과 갯수 모두 합하기
    var result = 0
    for i in boxes {
        result += (i.min()! * m)
    }
    return result
}