module Main where
import           Control.Monad (replicateM_)
import           Data.Bits     (Bits (testBit))
import           Data.Function (on)
import           Data.IntMap   (IntMap, findWithDefault)
import qualified Data.IntMap   as IntMap
import           Data.List     (group, maximumBy, sort)

toFreqTable :: Ord a => [a] -> [(a, Int)]
toFreqTable = fmap (\x -> (head x, length x)) . group . sort

toFreqMap :: [Int] -> IntMap Int
toFreqMap = IntMap.fromList . toFreqTable

alternative :: (Bits a, Num a) => a -> a
alternative x
  | testBit x 0 = x - 1
  | otherwise = x + 1

solve :: [Int] -> Int
solve xs = n - length (filter isMaxCandidate xs)
  where
  n = length xs
  freq = toFreqMap xs
  alxs = zip xs (alternative <$> xs)
  getFreq a = findWithDefault 0 a freq
  (maxa, maxb) = maximumBy (compare `on` (\(a, b) -> getFreq a + getFreq b)) alxs
  isMaxCandidate e = e == maxa || e == maxb

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
  _ <- getInt
  xs <- getInts
  print $ solve xs

main :: IO ()
main = getInt >>= flip replicateM_ doCase
