import Foundation

struct Score: Equatable {
    var atitude: Int
    var crew: Int
    init(_ atitude: Int, _ crew: Int) {
        self.atitude = atitude
        self.crew = crew
        self.sum = atitude + crew
    }
    var sum: Int
}

func solution(_ scores:[[Int]]) -> Int {
    let wonho: Score = .init(scores[0][0], scores[0][1])
    var bigger: [Score] = []
    for i in scores {
        if i[0] > wonho.atitude && i[1] > wonho.crew {
            return -1
        } else if i[0] + i[1] > wonho.sum {
            bigger.append(.init(i[0],i[1]))
        }
    }
    bigger.sort { $0.sum < $1.sum }
    var result = bigger.count
    for i in 0..<bigger.count {
        for j in i + 1..<bigger.count {
            if bigger[i].atitude < bigger[j].atitude && bigger[i].crew < bigger[j].crew {
                result -= 1
                break
            }
        }
    }
    return result + 1
}