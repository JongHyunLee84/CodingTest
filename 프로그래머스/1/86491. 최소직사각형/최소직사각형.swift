import Foundation

func solution(_ sizes:[[Int]]) -> Int {
    var maxArray: [Int] = []
    var minArray: [Int] = []
    
    for i in sizes {
        maxArray.append(i.max()!)
        minArray.append(i.min()!)
    }
    return maxArray.max()! * minArray.max()!
}

  //   var array = sizes.flatMap { $0 }.sorted(by: >)
  //   var width = array[0]
  //   var height = array[1]
  //   while true {
  //       var isAllTrue = false
  //       for i in sizes {
  //           if (i[0] <= width && i[1] <= height) || (i[1] <= width && i[0] <= height) {
  //               isAllTrue = true
  //           } else {
  //               isAllTrue = false
  //           }
  //       }
  //       if isAllTrue {
  //           height -= 1
  //       } else { break }
  //       print(width, height)
  //   }
  // return width * (height+1)