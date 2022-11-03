import Data.List (intercalate)
solve :: Int -> Int -> Int -> [(Int, Int)]
solve l r n
  | n == 1    = [(l, l)]
  | otherwise = take n zipped
  where
    zipped = zip (repeat odd) [l..r]
    odd
      | l `mod` 2 == 1    = l
      | otherwise         = l + 1

convert :: Read a => String -> [a]
convert = map read . words

myToString :: (Int, Int) -> String
myToString (a, b) = show a ++ " " ++ show b

main :: IO ()
main = do
       line <- getLine
       let [l, r, n] = convert line :: [Int]
       let ans = solve l r n
       let stringAns = map myToString ans
       putStrLn (intercalate "\n" stringAns)
