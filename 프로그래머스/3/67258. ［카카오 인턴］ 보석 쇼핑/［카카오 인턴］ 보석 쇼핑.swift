func solution(_ gems: [String]) -> [Int] {
    let uniqueGemsCount = Set(gems).count
    var gemDict = [String: Int]()
    var answer = [Int](repeating: 0, count: 2)
    var minLength = Int.max
    var start = 0
    
    for (i, gem) in gems.enumerated() {
        gemDict[gem, default: 0] += 1
        
        while gemDict.count == uniqueGemsCount {
            if i - start < minLength {
                minLength = i - start
                answer = [start + 1, i + 1] // 문제에서 요구하는 대로 1을 더함
            }
            
            if let count = gemDict[gems[start]], count > 1 {
                gemDict[gems[start]] = count - 1
            } else {
                gemDict.removeValue(forKey: gems[start])
            }
            start += 1
        }
    }
     
    return answer
}
