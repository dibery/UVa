# TLE
import re

class article:
    def __init__( self ):
        self.lines, self.words = [], []
        while True:
            s = input()
            if s == '**********':
                break
            self.lines.append( s )
            for w in re.sub( '[^a-z]', ' ', s.lower() ).split():
                self.words.append( w )
    def find( self, term, term2 = '' ):
        found = []
        for l in self.lines:
            try:
                re.sub( '[^a-z]', ' ', l.lower() ).split().index( term )
                found.append( l )
            except:
                if term2 != '':
                    try:
                        re.sub( '[^a-z]', ' ', l.lower() ).split().index( term2 )
                        found.append( l )
                    except:
                        pass
        return '\n'.join( found )
    def exist( self, term ):
        try:
            self.words.index( term )
            return True
        except:
            return False

collection = []
for i in range( int( input() ) ):
    collection.append( article() )

for i in range( int( input() ) ):
    key, found = input().split(), []
    if len( key ) == 1:
        for c in collection:
            found.append( c.find( key[ 0 ] ) )
    elif len( key ) == 2:
        for c in collection:
            if c.find( key[ 1 ] ) == '':
                found.append( '\n'.join( c.lines ) )
    elif key[ 1 ] == 'AND':
        for c in collection:
            if c.exist( key[ 0 ] ) & c.exist( key[ 2 ] ):
                found.append( c.find( key[ 0 ], key[ 2 ] ) )
    else:
        for c in collection:
            if c.exist( key[ 0 ] ) | c.exist( key[ 2 ] ):
                found.append( c.find( key[ 0 ], key[ 2 ] ) )

    found = [ f for f in found if f != '' ]
    if len( found ) == 0:
        print( 'Sorry, I found nothing.' )
    else:
        print( '\n---------\n'.join( found ) )
    print( '==========' )
