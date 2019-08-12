import React from "react";
import { View, Text, SafeAreaView, Image, StyleSheet, TouchableOpacity } from "react-native";

import logo from '../assets/logo.png';
import like from '../assets/like.png';
import dislike from '../assets/dislike.png';

export default function Main() {
    return (
        <SafeAreaView style={styles.container} >
            <Image style={styles.logo} source={logo} />
            <View style={styles.cardsContainer}>
                <View style={[styles.cards, { zIndex: 3 }]}>
                    <Image style={styles.avatar} source={{ uri: 'https://avatars2.githubusercontent.com/u/2254731?v=4' }}></Image>
                    <View style={styles.footer}>
                        <Text style={styles.name}>Diego Fernandes</Text>
                        <Text style={styles.bio} numberOfLines={3}>alguma coisa gdfgdfgdfg gfdg gfdg gdfgsdfhgfhjty tyrtsrtg  bvbgfhtrytrs sdssg dwddd</Text>
                    </View>
                </View>

                <View style={[styles.cards, { zIndex: 2 }]}>
                    <Image style={styles.avatar} source={{ uri: 'https://avatars2.githubusercontent.com/u/2254731?v=4' }}></Image>
                    <View style={styles.footer}>
                        <Text style={styles.name}>Diego Fernandes</Text>
                        <Text style={styles.bio} numberOfLines={3}>alguma coisa gdfgdfgdfg gfdg gfdg gdfgsdfhgfhjty tyrtsrtg  bvbgfhtrytrs sdssg dwddd</Text>
                    </View>
                </View>

                <View style={[styles.cards, { zIndex: 1 }]}>
                    <Image style={styles.avatar} source={{ uri: 'https://avatars2.githubusercontent.com/u/2254731?v=4' }}></Image>
                    <View style={styles.footer}>
                        <Text style={styles.name}>Diego Fernandes</Text>
                        <Text style={styles.bio} numberOfLines={3}>alguma coisa gdfgdfgdfg gfdg gfdg gdfgsdfhgfhjty tyrtsrtg  bvbgfhtrytrs sdssg dwddd</Text>
                    </View>
                </View>
            </View>
            <View style={styles.buttonsContainer}>
                <TouchableOpacity style={styles.button} >

                </TouchableOpacity>
            </View>
        </SafeAreaView>
    );
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: '#f5f5f5',
        alignItems: 'center',
        justifyContent: 'space-between',
    },

    logo: {
        marginTop: 30,
    },

    cardsContainer: {
        flex: 1,
        alignSelf: 'stretch',
        justifyContent:'center',
        maxHeight: 800,
    },

    cards: {
        borderWidth: 1,
        borderColor: '#DDD',
        alignSelf: 'center',
        borderRadius: 8,
        margin: 120,
        paddingHorizontal: 115,
        overflow: 'hidden',
        position: 'absolute',
        top: 0,
        left: 0,
        right: 0,
        bottom: 0,
    },

    avatar: {
        flex: 1,
        height: 100, 
    },

    footer: {
        backgroundColor: '#FFF',
        paddingHorizontal: 20,
        paddingVertical: 15,
    },

    name: {
        fontSize: 16,
        fontWeight: 'bold',
        color: '#333',
    },

    bio: {
        fontSize: 14,
        color: '#999',
        marginTop: 5,
        lineHeight: 18,
    },
});
