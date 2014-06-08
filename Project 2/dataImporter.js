/**
 * This code needs to be run on 
 * http://www.behindthename.com/random/random.php?number=1&gender=both&surname=&randomsurname=yes&all=yes
 */

var runInterval = setInterval( function(){$('#fuck').click(); }, 1000 );

function run(){
    runInterval = setInterval( function(){$('#fuck').click(); }, 1000 );
}
function stop(){
    clearInterval( runInterval );
}

function rand(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

function getT(){
    switch(rand(0,2)){
        case 0: return 'emp';
        case 1: return 'int';
        case 2: return 'vol';
    }
}

$( 'body').append( '<button id="fuck">populate</button><div id="count">0</div><pre id="shit" style="background:grey;"></pre>' );

$( '#fuck' ).on( 'click', function(){
    $.ajax({
        url : "http://www.behindthename.com/random/random.php?number=1&gender=both&surname=&randomsurname=yes&all=yes",
        type: "html",
        method: 'get',
        complete : function( data ){
          var m = [];
          m = data.responseText.match( /<a class="plain" href=".+?">(.+?)<\/a>/gm );
          var fn = m[0].replace( /^.+?>(.+?)<\/.>/g, "$1" );
          var ln = m[1].replace( /^.+?>(.+?)<\/.>/g, "$1" );
          
          var x = parseInt( $('#count').text() );
          $('#count').text( x + 1 );
          var c = [];
          c[0] = getT(); //t
          c[1] = x + 1; //id
          c[2] = fn; //fn 
          c[3] = ln; //ln
          c[4] = rand ( 18, 70);  //ag
          c[5] = rand ( 0, 1); //s
          if(c[0] == "int" ){
            c[6] = rand(0,1); //ip
            c[7] = c[6] == 1 ? rand(8, 50) : 0;  //p
            c[8] = rand(0, 200); //h
          }else if( c[0] == "vol"){
            c[6] = rand(0, 200); //h
          }else{
            c[6] = rand(8, 50);  //p
            c[7] = rand(0, 200); //h
          }
          
          var s = $( '#shit' ).html();
          for( var i = 0; i < c.length; i++){
            s += c[i]+ "\t";
          }
          s += "~\n";
          $( '#shit' ).html( s );
        }
    });
});


