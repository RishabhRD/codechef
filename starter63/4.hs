module Main where
import           Control.Arrow ((>>>))
import           Control.Monad (replicateM_)
import           Data.Array    as Array (Ix (range), listArray, (!))
import           Data.Char     (ord)
import qualified Data.List

rightShift :: Char -> Char -> Int
rightShift x y = ((ord y - ord x) + 26) `mod` 26

solve :: String -> String -> Int
solve a' b' =  dfs 0 0
  where
  n = length a'
  a = Array.listArray (0, n - 1) a'
  b = Array.listArray (0, n - 1) b'
  a2b i = rightShift (a ! i) (b ! i)
  b2a i = rightShift (b ! i) (a ! i)
  dfs i prevSum = min (valueOf (i + 1, prevSum + a2b i)) (valueOf (i + 1, prevSum - b2a i))
  valueOf (i, prevSum)
    | prevSum < -25 || prevSum > 25 = 26
    | i == n = abs prevSum
    | otherwise = dp ! (i, prevSum)
  bounds = ((0, -25), (n - 1, 25))
  dp = Array.listArray bounds $ uncurry dfs <$> Array.range bounds

parseInt :: String -> Int
parseInt = read

getInts :: IO [Int]
getInts = fmap (fmap parseInt) $ words <$> getLine

getInt :: IO Int
getInt = head <$> getInts

doCase :: IO ()
doCase = do
  _ <- getInt
  a <- getLine
  b <- getLine
  print $ solve a b

main :: IO ()
main = getInt >>= flip replicateM_ doCase
