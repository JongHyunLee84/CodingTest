import Foundation

func solution(_ cards1:[String], _ cards2:[String], _ goal:[String]) -> String {
    // card1과 card2의 첫번째 중 goal의 첫 번째 요소에 해당 하는 것이 있다면
    // 해당 card의 해당 요소 삭제 goal의 첫 번째 요소 삭제
    // 반복해서 goal이 빈배열이 된다면 true, 양쪽 카드 수의 합만큼 반복했는데 되지 않거나?, goal의 다음 첫번째 요소가 card1,2의 첫번째 요소 중 없다면 false
    var card1 = cards1, card2 = cards2, goal = goal
    
    for _ in 0..<goal.count {
        if let card = card1.first, card == goal.first {
            card1.removeFirst()
            goal.removeFirst()
        } else if let card = card2.first, card == goal.first {
            card2.removeFirst()
            goal.removeFirst()
        }
    }
    if goal.isEmpty {
        return "Yes"
    } else {
        return "No"
    }
}