func solution(_ genres:[String], _ plays:[Int]) -> [Int] {
    var genresDic: [String: Int] = [:]
    var genresSongs: [String: [Int]] = [:]
    for i in 0..<genres.count {
        genresDic[genres[i], default: 0] += plays[i]
        genresSongs[genres[i], default: []].append(i)
    }
    var sortedDic = genresDic.sorted(by: {
        $0.value > $1.value
    })
    var ret: [Int] = []
    for i in sortedDic {
        var tempDic: [Int: Int] = [:]
        for j in genresSongs[i.key, default: []] {
            tempDic[j, default: 0] = plays[j]
        }
        var tempRet = tempDic.sorted(by: {
            if $0.value == $1.value {
                return $0.key < $1.key
            }else {
                return $0.value > $1.value
            }
        })
        var tempArray = tempRet.map { $0.key }
        for _ in 0...1 {
            if tempArray.first != nil {
                ret.append(tempArray[0])
                tempArray.removeFirst()
            }
        }
    }
    return ret
}
