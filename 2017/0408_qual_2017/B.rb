def solve(times)
  n = gets.to_i
  m = 1
  kouho = [n]
  loop do
    u = under_zero(n, m)
    break if u.nil?
    kouho << u
    m += 1
  end
  # p kouho
  ans = nil
  kouho.sort.reverse.each{|x|
    if tidy?(x)
      ans = x
      break
    end
  }
  puts "Case ##{times}: #{ans}"
end

def under_zero(n, m)
  x = 10 ** m
  if n < x
    return nil
  else
    return ((n/x) * x) - 1
  end
end

def tidy?(n)
  m = n.to_s.split("").sort.join.to_i
  # p n.to_s.split("")
  return (m == n)
end

t = gets.to_i
for i in 1..t
  solve(i)
end
