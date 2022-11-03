solve :: [Int] -> Int
solve l = length (filter (< 0) l)

main :: IO ()
main = do
  firstLine <- getLine
  [1 .. (read firstLine :: Int)]

