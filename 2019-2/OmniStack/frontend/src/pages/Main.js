import React from 'react';
import './Main.css';

import logo from '../assets/logo.svg';
import dislike from '../assets/dislike.svg';
import like from '../assets/like.svg';

export default function Main({ match }) {
    return (
        <div className="main-container">
            <img src={logo} alt="Tindev" />
            <ul>
                <li>
                    <img src="https://avatars0.githubusercontent.com/u/42010291?v=4" alt="" />
                    <footer>
                        <strong>
                            Bruno Angst
                        </strong>
                        <p>
                            Começando como Dev dfsffffsdfddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
                        </p>

                        <div className="buttons">
                            <button type="button">
                                <img src={dislike} alt="Dislike" />
                            </button>
                            <button type="button">
                                <img src={like} alt="Like" />
                            </button>
                        </div>
                    </footer>
                </li>
                <li>
                    <img src="https://avatars0.githubusercontent.com/u/42010291?v=4" alt="" />
                    <footer>
                        <strong>
                            Bruno Angst
                        </strong>
                        <p>
                            Começando como Dev
                        </p>

                        <div className="buttons">
                            <button type="button">
                                <img src={dislike} alt="Dislike" />
                            </button>
                            <button type="button">
                                <img src={like} alt="Like" />
                            </button>
                        </div>
                    </footer>
                </li>
                <li>
                    <img src="https://avatars0.githubusercontent.com/u/42010291?v=4" alt="" />
                    <footer>
                        <strong>
                            Bruno Angst
                        </strong>
                        <p>
                            Começando como Dev
                        </p>

                        <div className="buttons">
                            <button type="button">
                                <img src={dislike} alt="Dislike" />
                            </button>
                            <button type="button">
                                <img src={like} alt="Like" />
                            </button>
                        </div>
                    </footer>
                </li>
                <li>
                    <img src="https://avatars0.githubusercontent.com/u/42010291?v=4" alt="" />
                    <footer>
                        <strong>
                            Bruno Angst
                        </strong>
                        <p>
                            Começando como Dev
                        </p>

                        <div className="buttons">
                            <button type="button">
                                <img src={dislike} alt="Dislike" />
                            </button>
                            <button type="button">
                                <img src={like} alt="Like" />
                            </button>
                        </div>
                    </footer>
                </li>
            </ul>
        </div>
    );
}
