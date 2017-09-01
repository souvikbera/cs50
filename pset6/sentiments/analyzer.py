import nltk
import sys

from termcolor import colored

def main():
    if len(sys.argv)!=2:
        print("error")
        exit(1)
        
class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        
        self.pos=set()
        self.neg=set()
        fp=open(positives,"r")
        for line in fp:
            if line.startswith(';')==False and line.starswith('#')==False:
                line=line.strip()
                self.pos.add(line)
        fp.close()
        
        fp=open(negatives,"r")
        for line in fp:
            if line.startswith(';')==False and line.starswith('#')==False:
                line=line.strip()
                self.neg.add(line)
        fp.close()
            
            
        

        # TODO

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens=tokenizer.tokenize(text)
        score=0
        for word in tokens:
            word=word.lower()
            if word in self.pos:
                score += 1
            elif word in self.neg:
                score-= 1
            else:
                continue
        
        return score
        

        # TODO
        return 0
