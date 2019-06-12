//
//  functions.h
//  sawwave
//
//  Created by Maxi on 16/09/2016. thats my computers name!
//  Copyright © 2016 Maxi. All rights reserved.
//

#ifndef functions_h
#define functions_h

typedef struct
{
    float left_phase;
    float right_phase;
}
paTestData;




static int patestCallbackDB2( const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
{
    // Cast data passed through stream to our structure.
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) inputBuffer; // Prevent unused variable warning.
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++ = data->left_phase/2;  // left
        *out++ = data->right_phase/2;  // right
        // Generate simple sawtooth phaser that ranges between -1.0 and 1.0.
        data->left_phase += 0.01f;
        // When signal reaches top, drop back down.
        if( data->left_phase >= 1.0f ) data->left_phase -= 3.18f;
        data->right_phase=data->left_phase;
    }
    return 0;
}






static int patestCallbackEB2( const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
{
    // Cast data passed through stream to our structure.
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) inputBuffer; // Prevent unused variable warning.
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++ = data->left_phase/2;  // left
        *out++ = data->right_phase/2;  // right
        // Generate simple sawtooth phaser that ranges between -1.0 and 1.0.
        data->left_phase += 0.01f;
        // When signal reaches top, drop back down.
        if( data->left_phase >= 1.0f ) data->left_phase -= 2.84f;
        data->right_phase=data->left_phase;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////


















static int patestCallbackGB2( const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
{
    /* Cast data passed through stream to our structure. */
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) inputBuffer; /* Prevent unused variable warning. */
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++ = data->left_phase/2;  /* left */
        *out++ = data->right_phase/2;  /* right */
        /* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
        data->left_phase += 0.01f;
        /* When signal reaches top, drop back down. */
        if( data->left_phase >= 1.0f ) data->left_phase -= 2.38f;
        data->right_phase=data->left_phase;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////




















static int patestCallbackAB2( const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
{
    /* Cast data passed through stream to our structure. */
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) inputBuffer; /* Prevent unused variable warning. */
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++ = data->left_phase/2;  /* left */
        *out++ = data->right_phase/2;  /* right */
        /* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
        data->left_phase += 0.01f;
        /* When signal reaches top, drop back down. */
        if( data->left_phase >= 1.0f ) data->left_phase -= 2.13f; 
        data->right_phase=data->left_phase;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////
















static int patestCallbackBB2( const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
{
    /* Cast data passed through stream to our structure. */
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) inputBuffer; /* Prevent unused variable warning. */
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++ = data->left_phase/2;  /* left */
        *out++ = data->right_phase/2;  /* right */
        /* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
        data->left_phase += 0.01f;
        /* When signal reaches top, drop back down. */
        if( data->left_phase >= 1.0f ) data->left_phase -= 1.9f;
        data->right_phase=data->left_phase;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////



















static int patestCallbackDB3( const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
{
    /* Cast data passed through stream to our structure. */
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) inputBuffer; /* Prevent unused variable warning. */
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++ = data->left_phase/2;  /* left */
        *out++ = data->right_phase/2;  /* right */
        /* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
        data->left_phase += 0.01f;
        /* When signal reaches top, drop back down. */
        if( data->left_phase >= 1.0f ) data->left_phase -= 1.59f;
        data->right_phase=data->left_phase;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////

















static int patestCallbackEB3( const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
{
    /* Cast data passed through stream to our structure. */
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) inputBuffer; /* Prevent unused variable warning. */
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++ = data->left_phase/2;  /* left */
        *out++ = data->right_phase/2;  /* right */
        /* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
        data->left_phase += 0.01f;
        /* When signal reaches top, drop back down. */
        if( data->left_phase >= 1.0f ) data->left_phase -= 1.42f;
        data->right_phase=data->left_phase;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////



















static int patestCallbackGB3( const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
{
    /* Cast data passed through stream to our structure. */
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) inputBuffer; /* Prevent unused variable warning. */
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++ = data->left_phase/2;  /* left */
        *out++ = data->right_phase/2;  /* right */
        /* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
        data->left_phase += 0.01f;
        /* When signal reaches top, drop back down. */
        if( data->left_phase >= 1.0f ) data->left_phase -= 1.19f;
        data->right_phase=data->left_phase;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////


















static int patestCallbackAB3( const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
{
    /* Cast data passed through stream to our structure. */
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) inputBuffer; /* Prevent unused variable warning. */
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++ = data->left_phase/2;  /* left */
        *out++ = data->right_phase/2;  /* right */
        /* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
        data->left_phase += 0.01f;
        /* When signal reaches top, drop back down. */
        if( data->left_phase >= 1.0f ) data->left_phase -= 1.06f;
        data->right_phase=data->left_phase;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////

















static int patestCallbackBB3( const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
{
    /* Cast data passed through stream to our structure. */
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) inputBuffer; /* Prevent unused variable warning. */
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++ = data->left_phase/2;  /* left */
        *out++ = data->right_phase/2;  /* right */
        /* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
        data->left_phase += 0.01f;
        /* When signal reaches top, drop back down. */
        if( data->left_phase >= 1.0f ) data->left_phase -= 0.948f;
        data->right_phase=data->left_phase;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////


















static int patestCallbackDB4( const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
{
    /* Cast data passed through stream to our structure. */
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) inputBuffer; /* Prevent unused variable warning. */
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++ = data->left_phase/2;  /* left */
        *out++ = data->right_phase/2;  /* right */
        /* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
        data->left_phase += 0.01f;
        /* When signal reaches top, drop back down. */
        if( data->left_phase >= 1.0f ) data->left_phase -= 0.797f;
        data->right_phase=data->left_phase;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////


















static int patestCallbackEB4( const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
{
    /* Cast data passed through stream to our structure. */
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) inputBuffer; /* Prevent unused variable warning. */
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++ = data->left_phase/2;  /* left */
        *out++ = data->right_phase/2;  /* right */
        /* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
        data->left_phase += 0.01f;
        /* When signal reaches top, drop back down. */
        if( data->left_phase >= 1.0f ) data->left_phase -= 0.71f;
        data->right_phase=data->left_phase;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////


















static int patestCallbackGB4( const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
{
    /* Cast data passed through stream to our structure. */
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) inputBuffer; /* Prevent unused variable warning. */
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++ = data->left_phase/2;  /* left */
        *out++ = data->right_phase/2;  /* right */
        /* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
        data->left_phase += 0.01f;
        /* When signal reaches top, drop back down. */
        if( data->left_phase >= 1.0f ) data->left_phase -= 0.597f;
        data->right_phase=data->left_phase;
    }
    return 0;
}



















static int patestCallbackAB4(const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
{
    // Cast data passed through stream to our structure.
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) inputBuffer; // Prevent unused variable warning.
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++ = data->left_phase/2;  // left
        *out++ = data->right_phase/2;  // right
        // Generate simple sawtooth phaser that ranges between -1.0 and 1.0.
        data->left_phase += 0.01f;
        // When signal reaches top, drop back down.
        if( data->left_phase >= 1.0f ) data->left_phase -= 0.53f;
        data->right_phase=data->left_phase;
    }
    return 0;
}





















static int patestCallbackBB4(const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
{
    // Cast data passed through stream to our structure.
    paTestData *data = (paTestData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;
    (void) inputBuffer; // Prevent unused variable warning.
    
    for( i=0; i<framesPerBuffer; i++ )
    {
        *out++ = data->left_phase/2;  // left
        *out++ = data->right_phase/2;  // right
        // Generate simple sawtooth phaser that ranges between -1.0 and 1.0.
        data->left_phase += 0.01f;
        // When signal reaches top, drop back down.                                                                                         
        if( data->left_phase >= 1.0f ) data->left_phase -= 0.475f;
        data->right_phase=data->left_phase;
    }
    return 0;
}


#endif /* functions_h */
