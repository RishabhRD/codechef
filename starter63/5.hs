module Main where
import           Control.Monad (replicateM_)
import           Data.Char     (ord)

solve :: String -> Int
solve x = initVal x + kadaneVal x
  where
  n = length x
  contri i = (i + 1) * (n - i)
  initVal = sum . fmap (contri . fst) . filter ((/='0').snd) . zip [0..]
  kadaneVal =  maximum . scanl kadaneOp 0 . fmap toWeight . zip [0..]
  toWeight (i, '0') = contri i
  toWeight (i, '1') = - (contri i)
  kadaneOp acc ele = max 0 (acc + ele)

charToInt :: Char -> Int
charToInt x = ord x - ord '0'

parseInt :: String -> Int
parseInt = read

getWords :: IO [String]
getWords = words <$> getLine

getInts :: IO [Int]
getInts = fmap (fmap parseInt) getWords

getInt :: IO Int
getInt = head <$> getInts

doCase :: IO ()
doCase = do
  str <- getLine
  print $ solve str

main :: IO ()
main = getInt >>= flip replicateM_ doCase
