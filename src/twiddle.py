def twiddle(tol=0.2, speed=1.0): 
    p = [0, 0, 0]
    dp = [1, 1, 1]
    robot = make_robot()
    x_trajectory, y_trajectory, best_err = run(robot, p, speed=speed)
    counter = 0
    while sum(dp) > tol:
        for i in range(len(p)):
            robot = make_robot()
            p[i] += dp[i]
            x_trajectory, y_trajectory, err = run(robot, p, speed=speed)
            if err < best_err:
                best_err = err
                dp[i] *= 1.1
            else:
                p[i] -= 2 * dp[i]
                robot = make_robot()
                x_trajectory, y_trajectory, err = run(robot, p, speed=speed)
                if err < best_err:
                    best_err = err
                    dp[i] *= 1.1
                else:
                    p[i] += dp[i]
                    dp[i] *= 0.9
        counter += 1
    
    return p, best_err, counter
