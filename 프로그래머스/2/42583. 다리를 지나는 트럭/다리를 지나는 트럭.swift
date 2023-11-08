func solution(_ bridge_length:Int, _ weight:Int, _ truck_weights:[Int]) -> Int {
    var onBridge: [Int] = []
    var outTime: [Int] = []
    var time = 0
    var pass = 0
    var index = 0
    while true {
        
        if pass == truck_weights.count { break }
        
        if index < truck_weights.count, onBridge.reduce(0, +) + truck_weights[index] <= weight {
            outTime.append(time + bridge_length)
            onBridge.append(truck_weights[index])
            index += 1
            if outTime[0] == time { 
                outTime.removeFirst()
                onBridge.removeFirst()
                pass += 1
            }
        } else {
            onBridge.removeFirst()
            time = outTime.removeFirst()
            pass += 1
            continue
        }
         time += 1
    }
    return time + 1
}


//     var time = 0
//     var index = 0
//     var timeArray: [Int] = []
//     var weightArray: [Int] = []
//     var pass = 0
//     while true {
//         if pass == truck_weights.count { break }
//         if timeArray.count > 0, time == timeArray.first! {
//             timeArray.removeFirst();
//             weightArray.removeFirst();
//             pass += 1
//         }
//         if index < truck_weights.count, weightArray.reduce(0, +) + truck_weights[index] <= weight && timeArray.count < bridge_length {
//             weightArray.append(truck_weights[index])
//             timeArray.append(time+bridge_length)
//             index += 1
            
//         }
//         time += 1
//     }
//     return time